#pragma once

#include <JuceHeader.h>
#include "myOpenGL.h"
#include "myOpenGL2D.h"
#include "myAnimatedPaint.h"


class myGui : public juce::Component,
    public juce::Button::Listener,
    public juce::Slider::Listener,
    public juce::ComboBox::Listener
{
public:

    myGui();
    ~myGui() override;

    void LOG(juce::String s);
    void paint(juce::Graphics& g) override;
    void resized() override;
    void buttonClicked(juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged(juce::Slider* sliderThatWasMoved) override;
    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;

private:

    double angleAlpha = 180;
    double angleTeta = 180;
    double anglePhi = 180;

    myopenGLComponent    myOpenGL;
    myopenGLComponent2D  myOpenGL2D;
    myAnimatedPaint      myAnimatedPaint;

    std::unique_ptr<juce::TextButton> juce__textButton11;
    std::unique_ptr<juce::Slider> juce__slider;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Slider> juce__slider2;
    std::unique_ptr<juce::Slider> juce__slider3;
    std::unique_ptr<juce::Slider> juce__slider4;
    std::unique_ptr<juce::Slider> juce__slider5;
    std::unique_ptr<juce::Slider> juce__slider6;
    std::unique_ptr<juce::ToggleButton> juce__toggleButton2;
    std::unique_ptr<juce::TextButton> juce__textButton2;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent;
    std::unique_ptr<juce::TextEditor> juce__textEditor;
    std::unique_ptr<juce::ComboBox> juce__comboBox;
    std::unique_ptr<juce::TextButton> juce__textButton4;
    std::unique_ptr<juce::TextButton> juce__textButton5;
    std::unique_ptr<juce::TextButton> juce__textButton6;
    std::unique_ptr<juce::TextButton> juce__textButton7;
    std::unique_ptr<juce::TextButton> juce__textButton8;
    std::unique_ptr<juce::TextButton> juce__textButton9;
    std::unique_ptr<juce::Slider> juce__slider8;
    std::unique_ptr<juce::TextButton> juce__textButton14;
    std::unique_ptr<juce::TextButton> juce__textButton13;
    std::unique_ptr<juce::TextButton> juce__textButton3;
    std::unique_ptr<juce::TextButton> juce__textButton10;
    std::unique_ptr<juce::TextButton> juce__textButton12;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(myGui)
};

