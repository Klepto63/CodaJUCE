/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class myGui : public juce::Component,
    public juce::Button::Listener,
    public juce::Slider::Listener,
    public juce::ComboBox::Listener,
    //public juce::AudioAppComponent,
    //public juce::ChangeListener
{
public:
    //==============================================================================
    myGui();
    ~myGui() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void LOG(juce::String s);
    //[/UserMethods]

    void paint(juce::Graphics& g) override;
    void resized() override;
    void buttonClicked(juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged(juce::Slider* sliderThatWasMoved) override;
    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    double FakeAngle1Recall = 180;
    double FakeAngle2Recall = 180;
    double FakeAngle3Recall = 180;
    //[/UserVariables]

    //==============================================================================
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


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(myGui)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

