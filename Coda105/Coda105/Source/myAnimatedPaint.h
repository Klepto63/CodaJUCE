#pragma once
#include <map>
#include <JuceHeader.h>

class myAnimatedPaint : public juce::AnimatedAppComponent
{
public:

    myAnimatedPaint()
    {
        setSize(600, 600);
        setFramesPerSecond(60);
    }

    void update() override
    {
        // This function is called at the frequency specified by the setFramesPerSecond() call
        // in the constructor. You can use it to update counters, animate values, etc.
    }


    void drawCirclePolar(juce::Graphics& g, float dist, float angle, float rad, juce::Colour color)
    {
        //Point repère : drawcircle(g, 0.5, 0.85, 40, juce::Colours::white);
        float x = 0.5 + dist * (std::cos(angle * 2 * 3.1415 / 360));
        float y = 0.5 - dist * (std::sin(angle * 2 * 3.1415 / 360));
        //float y = 0.95 - dist * (std::sin(angle * 2 * 3.1415 / 360));
        drawcircle(g, x, y, rad, color);
    }

    void drawcircle(juce::Graphics& g, float x, float y, float rad, juce::Colour color)
    {
        g.setColour(juce::Colours::white);
        auto w = getLocalBounds().toFloat().getWidth();
        auto h = getLocalBounds().toFloat().getHeight();
        g.setColour(color);
        g.fillEllipse((w * x) - (rad * 0.5f), (h * y) - (rad * 0.5f), rad, rad);
    }


    void paint(juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::black);
        g.setColour(getLookAndFeel().findColour(juce::Slider::thumbColourId));
        

        drawCirclePolar(g,
            0.3,
            getFrameCounter(),
            40,
            juce::Colours::red);

        /*
        auto fishLength = 10;
        juce::Path spinePath;
        for (auto i = 0; i < fishLength; ++i)
        {
            auto radius = 100 + 10 * std::sin((float)getFrameCounter() * 0.1f + (float)i * 0.5f);
            g.setColour(juce::Colours::red);
            juce::Point<float> p((float)getWidth() / 2.0f + 1.5f * (float)radius * std::sin((float)getFrameCounter() * 0.02f + (float)i * 0.12f),
                (float)getHeight() / 2.0f + 1.0f * (float)radius * std::cos((float)getFrameCounter() * 0.04f + (float)i * 0.12f));

            g.fillEllipse(p.x - (float)i, p.y - (float)i, 2.0f + 2.0f * (float)i, 2.0f + 2.0f * (float)i);     // [1]

            if (i == 0)
                spinePath.startNewSubPath(p);  
            else
                spinePath.lineTo(p);           
        }
                //g.strokePath(spinePath, juce::PathStrokeType(4.0f));
        */
    }

    void resized() override
    {

    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(myAnimatedPaint)
};
