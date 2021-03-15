#pragma once
#include <map>

class WavefrontObjFile
{
public:
    WavefrontObjFile() {}

    juce::Result load(const juce::String& objFileContent)
    {
        shapes.clear();
        return parseObjFile(juce::StringArray::fromLines(objFileContent));
    }

    juce::Result load(const juce::File& file)
    {
        sourceFile = file;
        return load(file.loadFileAsString());
    }

    typedef juce::uint32 Index;
    struct Vertex { float x, y, z; };
    struct TextureCoord { float x, y; };

    struct Mesh
    {
        juce::Array<Vertex> vertices, normals;
        juce::Array<TextureCoord> textureCoords;
        juce::Array<Index> indices;
    };

    struct Material
    {
        Material() noexcept
        {
            juce::zerostruct(ambient);
            juce::zerostruct(diffuse);
            juce::zerostruct(specular);
            juce::zerostruct(transmittance);
            juce::zerostruct(emission);
        }

        juce::String name;

        Vertex ambient, diffuse, specular, transmittance, emission;
        float shininess = 1.0f, refractiveIndex = 0.0f;

        juce::String ambientTextureName, diffuseTextureName,
            specularTextureName, normalTextureName;

        juce::StringPairArray parameters;
    };

    struct Shape
    {
        juce::String name;
        Mesh mesh;
        Material material;
    };

    juce::OwnedArray<Shape> shapes;

private:
    juce::File sourceFile;

    struct TripleIndex
    {
        TripleIndex() noexcept {}

        bool operator< (const TripleIndex& other) const noexcept
        {
            if (this == &other)
                return false;

            if (vertexIndex != other.vertexIndex)
                return vertexIndex < other.vertexIndex;

            if (textureIndex != other.textureIndex)
                return textureIndex < other.textureIndex;

            return normalIndex < other.normalIndex;
        }

        int vertexIndex = -1, textureIndex = -1, normalIndex = -1;
    };

    struct IndexMap
    {
        std::map<TripleIndex, Index> map;

        Index getIndexFor(TripleIndex i, Mesh& newMesh, const Mesh& srcMesh)
        {
            const std::map<TripleIndex, Index>::iterator it(map.find(i));

            if (it != map.end())
                return it->second;

            auto index = (Index)newMesh.vertices.size();

            if (juce::isPositiveAndBelow(i.vertexIndex, srcMesh.vertices.size()))
                newMesh.vertices.add(srcMesh.vertices.getReference(i.vertexIndex));

            if (juce::isPositiveAndBelow(i.normalIndex, srcMesh.normals.size()))
                newMesh.normals.add(srcMesh.normals.getReference(i.normalIndex));

            if (juce::isPositiveAndBelow(i.textureIndex, srcMesh.textureCoords.size()))
                newMesh.textureCoords.add(srcMesh.textureCoords.getReference(i.textureIndex));

            map[i] = index;
            return index;
        }
    };

    static float parseFloat(juce::String::CharPointerType& t)
    {
        t = t.findEndOfWhitespace();
        return (float)juce::CharacterFunctions::readDoubleValue(t);
    }

    static Vertex parseVertex(juce::String::CharPointerType t)
    {
        Vertex v;
        v.x = parseFloat(t);
        v.y = parseFloat(t);
        v.z = parseFloat(t);
        return v;
    }

    static TextureCoord parseTextureCoord(juce::String::CharPointerType t)
    {
        TextureCoord tc;
        tc.x = parseFloat(t);
        tc.y = parseFloat(t);
        return tc;
    }

    static bool matchToken(juce::String::CharPointerType& t, const char* token)
    {
        auto len = (int)strlen(token);

        if (juce::CharacterFunctions::compareUpTo(juce::CharPointer_ASCII(token), t, len) == 0)
        {
            auto end = t + len;

            if (end.isEmpty() || end.isWhitespace())
            {
                t = end.findEndOfWhitespace();
                return true;
            }
        }
        return false;
    }

    struct Face
    {
        Face(juce::String::CharPointerType t)
        {
            while (!t.isEmpty())
                triples.add(parseTriple(t));
        }

        juce::Array<TripleIndex> triples;

        void addIndices(Mesh& newMesh, const Mesh& srcMesh, IndexMap& indexMap)
        {
            TripleIndex i0(triples[0]), i1, i2(triples[1]);

            for (auto i = 2; i < triples.size(); ++i)
            {
                i1 = i2;
                i2 = triples.getReference(i);

                newMesh.indices.add(indexMap.getIndexFor(i0, newMesh, srcMesh));
                newMesh.indices.add(indexMap.getIndexFor(i1, newMesh, srcMesh));
                newMesh.indices.add(indexMap.getIndexFor(i2, newMesh, srcMesh));
            }
        }

        static TripleIndex parseTriple(juce::String::CharPointerType& t)
        {
            TripleIndex i;

            t = t.findEndOfWhitespace();
            i.vertexIndex = t.getIntValue32() - 1;
            t = findEndOfFaceToken(t);

            if (t.isEmpty() || t.getAndAdvance() != '/')
                return i;

            if (*t == '/')
            {
                ++t;
            }
            else
            {
                i.textureIndex = t.getIntValue32() - 1;
                t = findEndOfFaceToken(t);

                if (t.isEmpty() || t.getAndAdvance() != '/')
                    return i;
            }

            i.normalIndex = t.getIntValue32() - 1;
            t = findEndOfFaceToken(t);
            return i;
        }

        static juce::String::CharPointerType findEndOfFaceToken(juce::String::CharPointerType t) noexcept
        {
            return juce::CharacterFunctions::findEndOfToken(t, juce::CharPointer_ASCII("/ \t"), juce::String().getCharPointer());
        }
    };

    static Shape* parseFaceGroup(const Mesh& srcMesh,
        juce::Array<Face>& faceGroup,
        const Material& material,
        const juce::String& name)
    {
        if (faceGroup.size() == 0)
            return nullptr;

        std::unique_ptr<Shape> shape(new Shape());
        shape->name = name;
        shape->material = material;

        IndexMap indexMap;

        for (auto& f : faceGroup)
            f.addIndices(shape->mesh, srcMesh, indexMap);

        return shape.release();
    }

    juce::Result parseObjFile(const juce::StringArray& lines)
    {
        Mesh mesh;
        juce::Array<Face> faceGroup;
        juce::Array<Material> knownMaterials;
        Material lastMaterial;
        juce::String lastName;

        for (auto lineNum = 0; lineNum < lines.size(); ++lineNum)
        {
            auto l = lines[lineNum].getCharPointer().findEndOfWhitespace();

            if (matchToken(l, "v")) { mesh.vertices.add(parseVertex(l));            continue; }
            if (matchToken(l, "vn")) { mesh.normals.add(parseVertex(l));             continue; }
            if (matchToken(l, "vt")) { mesh.textureCoords.add(parseTextureCoord(l)); continue; }
            if (matchToken(l, "f")) { faceGroup.add(Face(l));                       continue; }
            if (matchToken(l, "usemtl"))
            {
                auto name = juce::String(l).trim();

                for (auto i = knownMaterials.size(); --i >= 0;)
                {
                    if (knownMaterials.getReference(i).name == name)
                    {
                        lastMaterial = knownMaterials.getReference(i);
                        break;
                    }
                }

                continue;
            }

            if (matchToken(l, "mtllib"))
            {
                juce::Result r = parseMaterial(knownMaterials, juce::String(l).trim());
                continue;
            }

            if (matchToken(l, "g") || matchToken(l, "o"))
            {
                if (Shape* shape = parseFaceGroup(mesh, faceGroup, lastMaterial, lastName))
                    shapes.add(shape);

                faceGroup.clear();
                lastName = juce::StringArray::fromTokens(l, " \t", "")[0];
                continue;
            }
        }

        if (auto* shape = parseFaceGroup(mesh, faceGroup, lastMaterial, lastName))
            shapes.add(shape);

        return juce::Result::ok();
    }

    juce::Result parseMaterial(juce::Array<Material>& materials, const juce::String& filename)
    {
        jassert(sourceFile.exists());
        auto f = sourceFile.getSiblingFile(filename);

        if (!f.exists())
            return juce::Result::fail("Cannot open file: " + filename);

        auto lines = juce::StringArray::fromLines(f.loadFileAsString());

        materials.clear();
        Material material;

        for (auto line : lines)
        {
            auto l = line.getCharPointer().findEndOfWhitespace();

            if (matchToken(l, "newmtl")) { materials.add(material); material.name = juce::String(l).trim(); continue; }

            if (matchToken(l, "Ka")) { material.ambient = parseVertex(l); continue; }
            if (matchToken(l, "Kd")) { material.diffuse = parseVertex(l); continue; }
            if (matchToken(l, "Ks")) { material.specular = parseVertex(l); continue; }
            if (matchToken(l, "Kt")) { material.transmittance = parseVertex(l); continue; }
            if (matchToken(l, "Ke")) { material.emission = parseVertex(l); continue; }
            if (matchToken(l, "Ni")) { material.refractiveIndex = parseFloat(l);  continue; }
            if (matchToken(l, "Ns")) { material.shininess = parseFloat(l);  continue; }

            if (matchToken(l, "map_Ka")) { material.ambientTextureName = juce::String(l).trim(); continue; }
            if (matchToken(l, "map_Kd")) { material.diffuseTextureName = juce::String(l).trim(); continue; }
            if (matchToken(l, "map_Ks")) { material.specularTextureName = juce::String(l).trim(); continue; }
            if (matchToken(l, "map_Ns")) { material.normalTextureName = juce::String(l).trim(); continue; }

            auto tokens = juce::StringArray::fromTokens(l, " \t", "");

            if (tokens.size() >= 2)
                material.parameters.set(tokens[0].trim(), tokens[1].trim());
        }

        materials.add(material);
        return juce::Result::ok();
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WavefrontObjFile)
};

class openGLMaskComponent : public juce::OpenGLAppComponent
{
public:
    openGLMaskComponent()
    {
        setSize(800, 600);
        CodaIsConnected = false;
    }

    ~openGLMaskComponent() override
    {
        shutdownOpenGL();
    }

    void initialise() override
    {
        createShaders();
    }

    void shutdown() override
    {
        shader.reset();
        shape.reset();
        attributes.reset();
        uniforms.reset();
    }

    juce::Matrix3D<float> getProjectionMatrix() const
    {
        auto w = 0.07f / (0.25f + 0.1f);                                       // [1]
        auto h = w * getLocalBounds().toFloat().getAspectRatio(false);         // [2]

        return juce::Matrix3D<float>::fromFrustum(-w, w, -h, h, 4.0f, 30.0f);  // [3]
    }


    juce::Matrix3D<float> getViewMatrix() const
    {
        juce::Matrix3D<float> viewMatrix({ 0.0f, 0.0f, -10.0f });  
        juce::Matrix3D<float> rotationMatrix;

        if (!CodaIsConnected)
        {
            rotationMatrix = viewMatrix.rotation({ -0.0f,  6.0f * std::sin((float)getFrameCounter() * 0.008f),  0.0f });
        }
        else
        {
            rotationMatrix = viewMatrix.rotation({ (float) (angleAlpha/57.2957),   (float)((angleTeta+0)/ 57.2957),   (float)(anglePhi / 57.2957)});
        }

        return rotationMatrix * viewMatrix;                                     
    }

    void set_CodaIsConnected(bool b)
    {
        CodaIsConnected = b;
    }
    
    void render() override
    {
        jassert(juce::OpenGLHelpers::isContextActive());

        auto desktopScale = (float)openGLContext.getRenderingScale();
        juce::OpenGLHelpers::clear(juce::Colours::black);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glViewport(0,
            0,
            juce::roundToInt(desktopScale * (float)getWidth()),
            juce::roundToInt(desktopScale * (float)getHeight()));

        shader->use();

        if (uniforms->projectionMatrix.get() != nullptr)
            uniforms->projectionMatrix->setMatrix4(getProjectionMatrix().mat, 1, false);

        if (uniforms->viewMatrix.get() != nullptr)
            uniforms->viewMatrix->setMatrix4(getViewMatrix().mat, 1, false);

        shape->draw(openGLContext, *attributes);

        // Reset the element buffers so child Components draw correctly
        openGLContext.extensions.glBindBuffer(juce::GL_ARRAY_BUFFER, 0);
        openGLContext.extensions.glBindBuffer(juce::GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void paint(juce::Graphics& g) override
    {
    }

    void set_angle(double alpha, double teta, double phi)
    {
        angleAlpha = alpha;
        angleTeta = teta;
        anglePhi = phi;
    }

    void resized() override
    {
    }

    void createShaders()
    {
        vertexShader = R"(
            attribute vec4 position;
            attribute vec4 sourceColour;
            attribute vec2 textureCoordIn;

            uniform mat4 projectionMatrix;
            uniform mat4 viewMatrix;

            varying vec4 destinationColour;
            varying vec2 textureCoordOut;

            void main()
            {
                destinationColour = sourceColour;
                textureCoordOut = textureCoordIn;
                gl_Position = projectionMatrix * viewMatrix * position;
            })";

        fragmentShader =
#if JUCE_OPENGL_ES
            R"(varying lowp vec4 destinationColour;
               varying lowp vec2 textureCoordOut;)"
#else
            R"(varying vec4 destinationColour;
               varying vec2 textureCoordOut;)"
#endif
            R"(
               void main()
               {)"
#if JUCE_OPENGL_ES
            R"(    lowp vec4 colour = vec4(0.95, 0.57, 0.03, 0.7);)"
#else
            R"(    vec4 colour = vec4(0.25, 0.65, 0.95, 0.7);)" //face color
#endif
            R"(    gl_FragColor = colour;
               })";

        std::unique_ptr<juce::OpenGLShaderProgram> newShader(new juce::OpenGLShaderProgram(openGLContext));
        juce::String statusText;

        if (newShader->addVertexShader(juce::OpenGLHelpers::translateVertexShaderToV3(vertexShader))
            && newShader->addFragmentShader(juce::OpenGLHelpers::translateFragmentShaderToV3(fragmentShader))
            && newShader->link())
        {
            shape.reset();
            attributes.reset();
            uniforms.reset();

            shader.reset(newShader.release());
            shader->use();

            shape.reset(new Shape(openGLContext));
            attributes.reset(new Attributes(openGLContext, *shader));
            uniforms.reset(new Uniforms(openGLContext, *shader));

            statusText = "GLSL: v" + juce::String(juce::OpenGLShaderProgram::getLanguageVersion(), 2);
        }
        else
        {
            statusText = newShader->getLastError();
        }
    }
 
private:


    double angleAlpha;
    double angleTeta;
    double anglePhi;

    struct Vertex
    {
        float position[3];
        float normal[3];
        float colour[4];
        float texCoord[2];
    };

    struct Attributes
    {
 
        Attributes(juce::OpenGLContext& context, juce::OpenGLShaderProgram& shaderProgram)
        {
            position.reset(createAttribute(context, shaderProgram, "position"));
            normal.reset(createAttribute(context, shaderProgram, "normal"));
            sourceColour.reset(createAttribute(context, shaderProgram, "sourceColour"));
            textureCoordIn.reset(createAttribute(context, shaderProgram, "textureCoordIn"));
        }

        void enable(juce::OpenGLContext& context)
        {
            if (position.get() != nullptr)
            {
                context.extensions.glVertexAttribPointer(position->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
                context.extensions.glEnableVertexAttribArray(position->attributeID);
            }

            if (normal.get() != nullptr)
            {
                context.extensions.glVertexAttribPointer(normal->attributeID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 3));
                context.extensions.glEnableVertexAttribArray(normal->attributeID);
            }

            if (sourceColour.get() != nullptr)
            {
                context.extensions.glVertexAttribPointer(sourceColour->attributeID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 6));
                context.extensions.glEnableVertexAttribArray(sourceColour->attributeID);
            }

            if (textureCoordIn.get() != nullptr)
            {
                context.extensions.glVertexAttribPointer(textureCoordIn->attributeID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(float) * 10));
                context.extensions.glEnableVertexAttribArray(textureCoordIn->attributeID);
            }
        }

        void disable(juce::OpenGLContext& context)
        {
            if (position.get() != nullptr)       context.extensions.glDisableVertexAttribArray(position->attributeID);
            if (normal.get() != nullptr)         context.extensions.glDisableVertexAttribArray(normal->attributeID);
            if (sourceColour.get() != nullptr)   context.extensions.glDisableVertexAttribArray(sourceColour->attributeID);
            if (textureCoordIn.get() != nullptr) context.extensions.glDisableVertexAttribArray(textureCoordIn->attributeID);
        }

        std::unique_ptr<juce::OpenGLShaderProgram::Attribute> position, normal, sourceColour, textureCoordIn;

    private:
        static juce::OpenGLShaderProgram::Attribute* createAttribute(juce::OpenGLContext& context,
            juce::OpenGLShaderProgram& shader,
            const juce::String& attributeName)
        {
            if (context.extensions.glGetAttribLocation(shader.getProgramID(), attributeName.toRawUTF8()) < 0)
                return nullptr;

            return new juce::OpenGLShaderProgram::Attribute(shader, attributeName.toRawUTF8());
        }
    };

    struct Uniforms
    {
        Uniforms(juce::OpenGLContext& context, juce::OpenGLShaderProgram& shaderProgram)
        {
            projectionMatrix.reset(createUniform(context, shaderProgram, "projectionMatrix"));
            viewMatrix.reset(createUniform(context, shaderProgram, "viewMatrix"));
        }

        std::unique_ptr<juce::OpenGLShaderProgram::Uniform> projectionMatrix, viewMatrix;

    private:
        static juce::OpenGLShaderProgram::Uniform* createUniform(juce::OpenGLContext& context,
            juce::OpenGLShaderProgram& shaderProgram,
            const juce::String& uniformName)
        {
            if (context.extensions.glGetUniformLocation(shaderProgram.getProgramID(), uniformName.toRawUTF8()) < 0)
                return nullptr;

            return new juce::OpenGLShaderProgram::Uniform(shaderProgram, uniformName.toRawUTF8());
        }
    };

    struct Shape
    {
        Shape(juce::OpenGLContext& context)
        {
            auto dir = juce::File::getCurrentWorkingDirectory();

            int numTries = 0;

            while (!dir.getChildFile("Resources").exists() && numTries++ < 15)
                dir = dir.getParentDirectory();

            if (shapeFile.load(dir.getChildFile("Resources").getChildFile("face.obj")).wasOk())
                for (auto* s : shapeFile.shapes)
                    vertexBuffers.add(new VertexBuffer(context, *s));
        }

        void draw(juce::OpenGLContext& context, Attributes& glAttributes)
        {
            for (auto* vertexBuffer : vertexBuffers)
            {
                vertexBuffer->bind();

                glAttributes.enable(context);
                glDrawElements(GL_TRIANGLES, vertexBuffer->numIndices, GL_UNSIGNED_INT, nullptr);
                glAttributes.disable(context);
            }
        }
 
    private:
        struct VertexBuffer
        {

            VertexBuffer(juce::OpenGLContext& context, WavefrontObjFile::Shape& aShape) : openGLContext(context)
            {
                numIndices = aShape.mesh.indices.size();

                openGLContext.extensions.glGenBuffers(1, &vertexBuffer);
                openGLContext.extensions.glBindBuffer(juce::GL_ARRAY_BUFFER, vertexBuffer);

                juce::Array<Vertex> vertices;
                createVertexListFromMesh(aShape.mesh, vertices, juce::Colours::green);

                openGLContext.extensions.glBufferData(juce::GL_ARRAY_BUFFER,
                    static_cast<juce::GLsizeiptr> (static_cast<size_t> (vertices.size()) * sizeof(Vertex)),
                    vertices.getRawDataPointer(), juce::GL_STATIC_DRAW);

                openGLContext.extensions.glGenBuffers(1, &indexBuffer);
                openGLContext.extensions.glBindBuffer(juce::GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
                openGLContext.extensions.glBufferData(juce::GL_ELEMENT_ARRAY_BUFFER,
                    static_cast<juce::GLsizeiptr> (static_cast<size_t> (numIndices) * sizeof(juce::uint32)),
                    aShape.mesh.indices.getRawDataPointer(), juce::GL_STATIC_DRAW);
            }

            ~VertexBuffer()
            {
                openGLContext.extensions.glDeleteBuffers(1, &vertexBuffer);
                openGLContext.extensions.glDeleteBuffers(1, &indexBuffer);
            }

            void bind()
            {
                openGLContext.extensions.glBindBuffer(juce::GL_ARRAY_BUFFER, vertexBuffer);
                openGLContext.extensions.glBindBuffer(juce::GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
            }

            GLuint vertexBuffer, indexBuffer;
            int numIndices;
            juce::OpenGLContext& openGLContext;

            JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VertexBuffer)
        };

        WavefrontObjFile shapeFile;
        juce::OwnedArray<VertexBuffer> vertexBuffers;

        static void createVertexListFromMesh(const WavefrontObjFile::Mesh& mesh, juce::Array<Vertex>& list, juce::Colour colour)
        {
            auto scale = 0.2f;
            WavefrontObjFile::TextureCoord defaultTexCoord{ 0.5f, 0.5f };
            WavefrontObjFile::Vertex defaultNormal{ 0.5f, 0.5f, 0.5f };

            for (auto i = 0; i < mesh.vertices.size(); ++i)
            {
                const auto& v = mesh.vertices.getReference(i);
                const auto& n = i < mesh.normals.size() ? mesh.normals.getReference(i) : defaultNormal;
                const auto& tc = i < mesh.textureCoords.size() ? mesh.textureCoords.getReference(i) : defaultTexCoord;

                list.add({ { scale * v.x, scale * v.y, scale * v.z, },
                            { scale * n.x, scale * n.y, scale * n.z, },
                            { colour.getFloatRed(), colour.getFloatGreen(), colour.getFloatBlue(), colour.getFloatAlpha() },
                            { tc.x, tc.y } });                                  
            }
        }
    };

    bool CodaIsConnected;
    juce::String vertexShader;
    juce::String fragmentShader;

    std::unique_ptr<juce::OpenGLShaderProgram> shader;
    std::unique_ptr<Shape> shape;
    std::unique_ptr<Attributes> attributes;
    std::unique_ptr<Uniforms> uniforms;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(openGLMaskComponent)
};
