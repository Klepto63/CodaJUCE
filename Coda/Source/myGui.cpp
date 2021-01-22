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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "myGui.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
enum TransportState {
	Stopped,
	Starting,
	Playing,
	Stopping
};
//[/MiscUserDefs]

//==============================================================================
myGui::myGui()
{
	//[Constructor_pre] You can add your own custom stuff here..
	juce__textButton11.reset(new juce::TextButton("ButtonPresetB"));
	addAndMakeVisible(juce__textButton11.get());
	juce__textButton11->setButtonText(TRANS("B"));
	juce__textButton11->addListener(this);
	juce__textButton11->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));
	juce__textButton11->setColour(juce::TextButton::buttonOnColourId, juce::Colours::red);

	juce__slider.reset(new juce::Slider("SliderAngle1"));
	addAndMakeVisible(juce__slider.get());
	juce__slider->setRange(0, 360, 0.2);
	juce__slider->setSliderStyle(juce::Slider::LinearHorizontal);
	juce__slider->setTextBoxStyle(juce::Slider::TextBoxRight, false, 50, 20);
	juce__slider->setColour(juce::Slider::thumbColourId, juce::Colours::white);
	juce__slider->setColour(juce::Slider::textBoxTextColourId, juce::Colours::aqua);
	juce__slider->addListener(this);

	juce__label.reset(new juce::Label("new label",
		TRANS("Studio Coda Sandbox")));
	addAndMakeVisible(juce__label.get());
	juce__label->setFont(juce::Font("Calibri", 21.00f, juce::Font::plain).withTypefaceStyle("Regular").withExtraKerningFactor(0.057f));
	juce__label->setJustificationType(juce::Justification::centredLeft);
	juce__label->setEditable(false, false, false);
	juce__label->setColour(juce::TextEditor::textColourId, juce::Colours::black);
	juce__label->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

	juce__label2.reset(new juce::Label("new label",
		TRANS("1.0.1")));
	addAndMakeVisible(juce__label2.get());
	juce__label2->setFont(juce::Font("Calibri", 12.70f, juce::Font::plain).withTypefaceStyle("Regular").withExtraKerningFactor(0.048f));
	juce__label2->setJustificationType(juce::Justification::centredLeft);
	juce__label2->setEditable(false, false, false);
	juce__label2->setColour(juce::TextEditor::textColourId, juce::Colours::black);
	juce__label2->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

	juce__slider2.reset(new juce::Slider("SliderAngle2"));
	addAndMakeVisible(juce__slider2.get());
	juce__slider2->setRange(0, 360, 0.2);
	juce__slider2->setSliderStyle(juce::Slider::LinearHorizontal);
	juce__slider2->setTextBoxStyle(juce::Slider::TextBoxRight, false, 50, 20);
	juce__slider2->setColour(juce::Slider::thumbColourId, juce::Colours::white);
	juce__slider2->setColour(juce::Slider::textBoxTextColourId, juce::Colours::aqua);
	juce__slider2->addListener(this);

	juce__slider3.reset(new juce::Slider("SliderAngle3"));
	addAndMakeVisible(juce__slider3.get());
	juce__slider3->setRange(0, 360, 0.2);
	juce__slider3->setSliderStyle(juce::Slider::LinearHorizontal);
	juce__slider3->setTextBoxStyle(juce::Slider::TextBoxRight, false, 50, 20);
	juce__slider3->setColour(juce::Slider::thumbColourId, juce::Colours::white);
	juce__slider3->setColour(juce::Slider::textBoxTextColourId, juce::Colours::aqua);
	juce__slider3->addListener(this);

	juce__slider4.reset(new juce::Slider("SliderAngleFake1"));
	addAndMakeVisible(juce__slider4.get());
	juce__slider4->setRange(0, 360, 1);
	juce__slider4->setValue(180);
	juce__slider4->setSliderStyle(juce::Slider::LinearHorizontal);
	juce__slider4->setTextBoxStyle(juce::Slider::TextBoxRight, false, 50, 20);
	juce__slider4->setColour(juce::Slider::thumbColourId, juce::Colours::white);
	juce__slider4->addListener(this);

	juce__slider5.reset(new juce::Slider("SliderAngleFake2"));
	addAndMakeVisible(juce__slider5.get());
	juce__slider5->setRange(00, 360, 1);
	juce__slider5->setValue(180);
	juce__slider5->setSliderStyle(juce::Slider::LinearHorizontal);
	juce__slider5->setTextBoxStyle(juce::Slider::TextBoxRight, false, 50, 20);
	juce__slider5->setColour(juce::Slider::thumbColourId, juce::Colours::white);
	juce__slider5->addListener(this);

	juce__slider6.reset(new juce::Slider("SliderAngleFake3"));
	addAndMakeVisible(juce__slider6.get());
	juce__slider6->setRange(0, 360, 1);
	juce__slider6->setValue(180);
	juce__slider6->setSliderStyle(juce::Slider::LinearHorizontal);
	juce__slider6->setTextBoxStyle(juce::Slider::TextBoxRight, false, 50, 20);
	juce__slider6->setColour(juce::Slider::thumbColourId, juce::Colours::white);
	juce__slider6->addListener(this);

	juce__toggleButton2.reset(new juce::ToggleButton("ButtonActivateFake"));
	addAndMakeVisible(juce__toggleButton2.get());
	juce__toggleButton2->setButtonText(TRANS("En"));
	juce__toggleButton2->addListener(this);
	//juce__toggleButton2->setToggleState (true, dontSendNotification);

	juce__textButton2.reset(new juce::TextButton("ButtonFakeAngleReset"));
	addAndMakeVisible(juce__textButton2.get());
	juce__textButton2->setButtonText(TRANS("reset"));
	juce__textButton2->addListener(this);
	juce__textButton2->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));

	juce__groupComponent.reset(new juce::GroupComponent("new group",
		TRANS("Manual Angle")));
	addAndMakeVisible(juce__groupComponent.get());

	juce__textEditor.reset(new juce::TextEditor("TextConsole"));
	addAndMakeVisible(juce__textEditor.get());
	juce__textEditor->setMultiLine(true);
	juce__textEditor->setReturnKeyStartsNewLine(true);
	juce__textEditor->setReadOnly(true);
	juce__textEditor->setScrollbarsShown(false);
	juce__textEditor->setCaretVisible(false);
	juce__textEditor->setPopupMenuEnabled(true);
	juce__textEditor->setScrollbarsShown(true);
	juce__textEditor->setColour(juce::TextEditor::backgroundColourId, juce::Colours::black);
	juce__textEditor->setText("sandbox V1.0.1");

	juce__comboBox.reset(new juce::ComboBox("new combo box"));
	addAndMakeVisible(juce__comboBox.get());
	juce__comboBox->setEditableText(false);
	juce__comboBox->setJustificationType(juce::Justification::centredLeft);
	juce__comboBox->setTextWhenNothingSelected(TRANS("Vivaldi - Winter"));
	juce__comboBox->setTextWhenNoChoicesAvailable(TRANS("(no choices)"));
	juce__comboBox->addItem(TRANS("Vivaldi - Winter"), 1);
	juce__comboBox->addItem(TRANS("Vivaldi - Summer"), 2);
	juce__comboBox->addSeparator();
	juce__comboBox->addListener(this);

	juce__textButton4.reset(new juce::TextButton("ButtonLoad"));
	addAndMakeVisible(juce__textButton4.get());
	juce__textButton4->setButtonText(TRANS("LOAD SONG"));
	juce__textButton4->addListener(this);
	juce__textButton4->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));

	juce__textButton5.reset(new juce::TextButton("ButtonPlay"));
	addAndMakeVisible(juce__textButton5.get());
	juce__textButton5->setButtonText(TRANS("PLAY"));
	juce__textButton5->addListener(this);
	juce__textButton5->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff113900));

	juce__textButton6.reset(new juce::TextButton("ButtonLoad"));
	addAndMakeVisible(juce__textButton6.get());
	juce__textButton6->setButtonText(TRANS("STOP"));
	juce__textButton6->addListener(this);
	juce__textButton6->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));

	juce__textButton7.reset(new juce::TextButton("ButtonCenter3D"));
	addAndMakeVisible(juce__textButton7.get());
	juce__textButton7->setButtonText(TRANS("CENTER"));
	juce__textButton7->addListener(this);
	juce__textButton7->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));

	juce__textButton8.reset(new juce::TextButton("ButtonFakeAngleSave"));
	addAndMakeVisible(juce__textButton8.get());
	juce__textButton8->setButtonText(TRANS("save"));
	juce__textButton8->addListener(this);
	juce__textButton8->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));

	juce__textButton9.reset(new juce::TextButton("ButtonPrequelConnect"));
	addAndMakeVisible(juce__textButton9.get());
	juce__textButton9->setButtonText(TRANS("Connect"));
	juce__textButton9->addListener(this);
	juce__textButton9->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));

	juce__slider8.reset(new juce::Slider("SliderVolume"));
	addAndMakeVisible(juce__slider8.get());
	juce__slider8->setRange(0, 100, 1);
	juce__slider8->setValue(70);
	juce__slider8->setSliderStyle(juce::Slider::LinearVertical);
	juce__slider8->setTextBoxStyle(juce::Slider::NoTextBox, false, 50, 20);
	juce__slider8->setColour(juce::Slider::thumbColourId, juce::Colours::white);
	juce__slider8->addListener(this);

	juce__textButton14.reset(new juce::TextButton("ButtonPresetA"));
	addAndMakeVisible(juce__textButton14.get());
	juce__textButton14->setButtonText(TRANS("A"));
	juce__textButton14->addListener(this);
	juce__textButton14->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));
	juce__textButton14->setColour(juce::TextButton::buttonOnColourId, juce::Colours::red);

	juce__textButton13.reset(new juce::TextButton("ButtonPresetC"));
	addAndMakeVisible(juce__textButton13.get());
	juce__textButton13->setButtonText(TRANS("C"));
	juce__textButton13->addListener(this);
	juce__textButton13->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));
	juce__textButton13->setColour(juce::TextButton::buttonOnColourId, juce::Colours::red);

	juce__textButton3.reset(new juce::TextButton("ButtonPrequelTest"));
	addAndMakeVisible(juce__textButton3.get());
	juce__textButton3->setButtonText(TRANS("Test"));
	juce__textButton3->addListener(this);
	juce__textButton3->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));

	juce__textButton10.reset(new juce::TextButton("ButtonPresetD"));
	addAndMakeVisible(juce__textButton10.get());
	juce__textButton10->setButtonText(TRANS("D"));
	juce__textButton10->addListener(this);
	juce__textButton10->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));
	juce__textButton10->setColour(juce::TextButton::buttonOnColourId, juce::Colours::red);

	juce__textButton12.reset(new juce::TextButton("ButtonPresetE"));
	addAndMakeVisible(juce__textButton12.get());
	juce__textButton12->setButtonText(TRANS("O"));
	juce__textButton12->addListener(this);
	juce__textButton12->setColour(juce::TextButton::buttonColourId, juce::Colour(0xff152525));
	juce__textButton12->setColour(juce::TextButton::buttonOnColourId, juce::Colours::red);


	//[UserPreSize]
	//[/UserPreSize]

	setSize(1300, 650);
	//setResizeLimits(1600, 800, 800, 400);

	//[Constructor] You can add your own custom stuff here..
	//[/Constructor]
}


void myGui::LOG(juce::String s)
{
	juce__textEditor->setText(juce__textEditor->getText() + "\r" + s);
}

myGui::~myGui()
{
	//[Destructor_pre]. You can add your own custom destruction code here..
	//[/Destructor_pre]

	juce__textButton11 = nullptr;
	juce__slider = nullptr;
	juce__label = nullptr;
	juce__label2 = nullptr;
	juce__slider2 = nullptr;
	juce__slider3 = nullptr;
	juce__slider4 = nullptr;
	juce__slider5 = nullptr;
	juce__slider6 = nullptr;
	juce__toggleButton2 = nullptr;
	juce__textButton2 = nullptr;
	juce__groupComponent = nullptr;
	juce__textEditor = nullptr;
	juce__comboBox = nullptr;
	juce__textButton4 = nullptr;
	juce__textButton5 = nullptr;
	juce__textButton6 = nullptr;
	juce__textButton7 = nullptr;
	juce__textButton8 = nullptr;
	juce__textButton9 = nullptr;
	juce__slider8 = nullptr;
	juce__textButton14 = nullptr;
	juce__textButton13 = nullptr;
	juce__textButton3 = nullptr;
	juce__textButton10 = nullptr;
	juce__textButton12 = nullptr;


	//[Destructor]. You can add your own custom destruction code here..
	//[/Destructor]
}

//==============================================================================
void myGui::paint(juce::Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(juce::Colour(0xff152525));

	{
		int x = proportionOfWidth(0.0285f), y = proportionOfHeight(0.2641f), width = proportionOfWidth(0.2238f), height = proportionOfHeight(0.3671f);
		juce::Colour fillColour = juce::Colours::black;
		//[UserPaintCustomArguments] Customize the painting arguments here..
		//[/UserPaintCustomArguments]
		g.setColour(fillColour);
		g.fillRect(x, y, width, height);
	}

	//[UserPaint] Add your own custom painting code here..
	//[/UserPaint]
}

void myGui::resized()
{
	//[UserPreResize] Add your own custom resize code here..
	//[/UserPreResize]

	juce__textButton11->setBounds(proportionOfWidth(0.3255f), proportionOfHeight(0.8631f), proportionOfWidth(0.0407f), proportionOfHeight(0.0773f));
	juce__slider->setBounds(proportionOfWidth(0.0244f), proportionOfHeight(0.1288f), proportionOfWidth(0.2197f), proportionOfHeight(0.0258f));
	juce__label->setBounds(proportionOfWidth(0.0081f), proportionOfHeight(0.0129f), proportionOfWidth(0.2523f), proportionOfHeight(0.0387f));
	juce__label2->setBounds(proportionOfWidth(0.0163f), proportionOfHeight(0.0515f), proportionOfWidth(0.0570f), 24);
	juce__slider2->setBounds(proportionOfWidth(0.0244f), proportionOfHeight(0.1675f), proportionOfWidth(0.2197f), proportionOfHeight(0.0258f));
	juce__slider3->setBounds(proportionOfWidth(0.0244f), proportionOfHeight(0.2061f), proportionOfWidth(0.2197f), proportionOfHeight(0.0258f));
	juce__slider4->setBounds(proportionOfWidth(0.0325f), proportionOfHeight(0.7472f), proportionOfWidth(0.2035f), proportionOfHeight(0.0258f));
	juce__slider5->setBounds(proportionOfWidth(0.0325f), proportionOfHeight(0.7858f), proportionOfWidth(0.2035f), proportionOfHeight(0.0258f));
	juce__slider6->setBounds(proportionOfWidth(0.0325f), proportionOfHeight(0.8245f), proportionOfWidth(0.2035f), proportionOfHeight(0.0258f));
	juce__toggleButton2->setBounds(proportionOfWidth(0.0407f), proportionOfHeight(0.8889f), proportionOfWidth(0.0488f), proportionOfHeight(0.0258f));
	juce__textButton2->setBounds(proportionOfWidth(0.0977f), proportionOfHeight(0.8889f), proportionOfWidth(0.0651f), proportionOfHeight(0.0258f));
	juce__groupComponent->setBounds(proportionOfWidth(0.0244f), proportionOfHeight(0.7085f), proportionOfWidth(0.2279f), proportionOfHeight(0.2319f));
	juce__textEditor->setBounds(proportionOfWidth(0.8383f), proportionOfHeight(0.0000f), proportionOfWidth(0.1628f), proportionOfHeight(1.0048f));
	juce__comboBox->setBounds(proportionOfWidth(0.2686f), proportionOfHeight(0.7858f), proportionOfWidth(0.2686f), proportionOfHeight(0.0515f));
	juce__textButton4->setBounds(proportionOfWidth(0.5534f), proportionOfHeight(0.7858f), proportionOfWidth(0.2116f), proportionOfHeight(0.0515f));
	juce__textButton5->setBounds(proportionOfWidth(0.6673f), proportionOfHeight(0.8631f), proportionOfWidth(0.0977f), proportionOfHeight(0.0773f));
	juce__textButton6->setBounds(proportionOfWidth(0.5534f), proportionOfHeight(0.8631f), proportionOfWidth(0.0977f), proportionOfHeight(0.0773f));
	juce__textButton7->setBounds(proportionOfWidth(0.1790f), proportionOfHeight(0.6441f), proportionOfWidth(0.0651f), proportionOfHeight(0.0258f));
	juce__textButton8->setBounds(proportionOfWidth(0.1709f), proportionOfHeight(0.8889f), proportionOfWidth(0.0651f), proportionOfHeight(0.0258f));
	juce__textButton9->setBounds(proportionOfWidth(0.0325f), proportionOfHeight(0.6441f), proportionOfWidth(0.0814f), proportionOfHeight(0.0258f));
	juce__slider8->setBounds(proportionOfWidth(0.7813f), proportionOfHeight(0.6828f), proportionOfWidth(0.0488f), proportionOfHeight(0.2705f));
	juce__textButton14->setBounds(proportionOfWidth(0.2686f), proportionOfHeight(0.8631f), proportionOfWidth(0.0407f), proportionOfHeight(0.0773f));
	juce__textButton13->setBounds(proportionOfWidth(0.3825f), proportionOfHeight(0.8631f), proportionOfWidth(0.0407f), proportionOfHeight(0.0773f));
	juce__textButton3->setBounds(proportionOfWidth(0.1221f), proportionOfHeight(0.6441f), proportionOfWidth(0.0488f), proportionOfHeight(0.0258f));
	juce__textButton10->setBounds(proportionOfWidth(0.4395f), proportionOfHeight(0.8631f), proportionOfWidth(0.0407f), proportionOfHeight(0.0773f));
	juce__textButton12->setBounds(proportionOfWidth(0.4964f), proportionOfHeight(0.8631f), proportionOfWidth(0.0407f), proportionOfHeight(0.0773f));
	//[UserResized] Add your own custom resize handling here..
	//[/UserResized]
}

void myGui::buttonClicked(juce::Button* buttonThatWasClicked)
{
	//[UserbuttonClicked_Pre]
	//[/UserbuttonClicked_Pre]

	if (buttonThatWasClicked == juce__textButton11.get())
	{
		//[UserButtonCode_juce__textButton11] -- add your button handler code here..
		LOG("Preset B");
		//[/UserButtonCode_juce__textButton11]
	}
	else if (buttonThatWasClicked == juce__toggleButton2.get())
	{
		//[UserButtonCode_juce__toggleButton2] -- add your button handler code here..		//toggle boutton 2
		if (juce__toggleButton2->getToggleStateValue() == true)
		{//on
			juce__slider->setValue(juce__slider4->getValue());
			juce__slider2->setValue(juce__slider5->getValue());
			juce__slider3->setValue(juce__slider6->getValue());
		}
		else
		{//off
			juce__slider->setValue(0);
			juce__slider2->setValue(0);
			juce__slider3->setValue(0);
		}
		//[/UserButtonCode_juce__toggleButton2]
	}
	else if (buttonThatWasClicked == juce__textButton2.get())								//Reset fake
	{
		//[UserButtonCode_juce__textButton2] -- add your button handler code here..
		juce__slider4->setValue(myGui::FakeAngle1Recall);
		juce__slider5->setValue(myGui::FakeAngle2Recall);
		juce__slider6->setValue(myGui::FakeAngle3Recall);
		//[/UserButtonCode_juce__textButton2]
	}
	else if (buttonThatWasClicked == juce__textButton4.get())
	{
		//[UserButtonCode_juce__textButton4] -- add your button handler code here..
		LOG("Loading " + juce__comboBox->getItemText(juce__comboBox->getSelectedId()));
		//[/UserButtonCode_juce__textButton4]
	}
	else if (buttonThatWasClicked == juce__textButton5.get())
	{
		//[UserButtonCode_juce__textButton5] -- add your button handler code here..
		LOG("PLAY");
		//[/UserButtonCode_juce__textButton5]
	}
	else if (buttonThatWasClicked == juce__textButton6.get())
	{
		//[UserButtonCode_juce__textButton6] -- add your button handler code here..
		LOG("STOP");
		//[/UserButtonCode_juce__textButton6]
	}
	else if (buttonThatWasClicked == juce__textButton7.get())
	{
		//[UserButtonCode_juce__textButton7] -- add your button handler code here..
		LOG("CENTER");
		//[/UserButtonCode_juce__textButton7]
	}
	else if (buttonThatWasClicked == juce__textButton8.get())
	{
		//[UserButtonCode_juce__textButton8] -- add your button handler code here..				//save fake
		myGui::FakeAngle1Recall = juce__slider4->getValue();
		myGui::FakeAngle2Recall = juce__slider5->getValue();
		myGui::FakeAngle3Recall = juce__slider6->getValue();
		//[/UserButtonCode_juce__textButton8]
	}
	else if (buttonThatWasClicked == juce__textButton9.get())
	{
		//[UserButtonCode_juce__textButton9] -- add your button handler code here..
		LOG("prequel connect");



		//[/UserButtonCode_juce__textButton9]
	}
	else if (buttonThatWasClicked == juce__textButton14.get())
	{
		//[UserButtonCode_juce__textButton14] -- add your button handler code here..
		LOG("Preset A");

		//[/UserButtonCode_juce__textButton14]
	}
	else if (buttonThatWasClicked == juce__textButton13.get())
	{
		//[UserButtonCode_juce__textButton13] -- add your button handler code here..
		LOG("Preset C");
		//[/UserButtonCode_juce__textButton13]
	}
	else if (buttonThatWasClicked == juce__textButton3.get())
	{
		//[UserButtonCode_juce__textButton3] -- add your button handler code here..
		LOG("prequel test");
		//[/UserButtonCode_juce__textButton3]
	}
	else if (buttonThatWasClicked == juce__textButton10.get())
	{
		//[UserButtonCode_juce__textButton10] -- add your button handler code here..
		LOG("Preset D");
		//[/UserButtonCode_juce__textButton10]
	}
	else if (buttonThatWasClicked == juce__textButton12.get())
	{
		//[UserButtonCode_juce__textButton12] -- add your button handler code here..
		LOG("Preset Original song");
		//[/UserButtonCode_juce__textButton12]
	}

	//[UserbuttonClicked_Post]
	//[/UserbuttonClicked_Post]
}

void myGui::sliderValueChanged(juce::Slider* sliderThatWasMoved)
{
	//[UsersliderValueChanged_Pre]
	//[/UsersliderValueChanged_Pre]

	if (sliderThatWasMoved == juce__slider.get())
	{
		//[UserSliderCode_juce__slider] -- add your slider handling code here..
		//[/UserSliderCode_juce__slider]
	}
	else if (sliderThatWasMoved == juce__slider2.get())
	{
		//[UserSliderCode_juce__slider2] -- add your slider handling code here..
		//[/UserSliderCode_juce__slider2]
	}
	else if (sliderThatWasMoved == juce__slider3.get())
	{
		//[UserSliderCode_juce__slider3] -- add your slider handling code here..
		//[/UserSliderCode_juce__slider3]
	}
	else if (sliderThatWasMoved == juce__slider4.get())
	{
		//[UserSliderCode_juce__slider4] -- add your slider handling code here..
		if (juce__toggleButton2->getToggleStateValue() == true)
		{
			juce__slider->setValue(juce__slider4->getValue());
		}

		//[/UserSliderCode_juce__slider4]
	}
	else if (sliderThatWasMoved == juce__slider5.get())
	{
		//[UserSliderCode_juce__slider5] -- add your slider handling code here..
		if (juce__toggleButton2->getToggleStateValue() == true)
		{
			juce__slider2->setValue(juce__slider5->getValue());
		}
		//[/UserSliderCode_juce__slider5]
	}
	else if (sliderThatWasMoved == juce__slider6.get())
	{
		//[UserSliderCode_juce__slider6] -- add your slider handling code here..
		if (juce__toggleButton2->getToggleStateValue() == true)
		{
			juce__slider3->setValue(juce__slider6->getValue());
		}
		//[/UserSliderCode_juce__slider6]
	}
	else if (sliderThatWasMoved == juce__slider8.get())
	{
		//[UserSliderCode_juce__slider8] -- add your slider handling code here..
		//[/UserSliderCode_juce__slider8]
	}

	//[UsersliderValueChanged_Post]
	//[/UsersliderValueChanged_Post]
}

void myGui::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
	//[UsercomboBoxChanged_Pre]
	//[/UsercomboBoxChanged_Pre]

	if (comboBoxThatHasChanged == juce__comboBox.get())
	{
		//[UserComboBoxCode_juce__comboBox] -- add your combo box handling code here..
		//[/UserComboBoxCode_juce__comboBox]
	}

	//[UsercomboBoxChanged_Post]
	//[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

	This is where the Projucer stores the metadata that describe this GUI layout, so
	make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="myGui" componentName="" parentClasses="public juce::Component"
				 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
				 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="1200"
				 initialHeight="600">
  <BACKGROUND backgroundColour="ff152525">
	<RECT pos="2.848% 26.409% 22.38% 36.715%" fill="solid: ff000000" hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="ButtonPresetA" id="dfe12eb3fe2acad" memberName="juce__textButton11"
			  virtualName="" explicitFocusOrder="0" pos="32.553% 86.312% 4.069% 7.729%"
			  bgColOff="ff152525" bgColOn="ffff0000" buttonText="B" connectedEdges="0"
			  needsCallback="1" radioGroupId="0"/>
  <SLIDER name="SliderAngle1" id="1205e96724cbc49f" memberName="juce__slider"
		  virtualName="" explicitFocusOrder="0" pos="2.442% 12.882% 21.974% 2.576%"
		  thumbcol="ffffffff" textboxtext="ff00ffff" min="0.0" max="360.0"
		  int="0.2" style="LinearHorizontal" textBoxPos="TextBoxRight"
		  textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
		  needsCallback="1"/>
  <LABEL name="new label" id="919a27bd1d80d348" memberName="juce__label"
		 virtualName="" explicitFocusOrder="0" pos="0.814% 1.288% 25.229% 3.865%"
		 edTextCol="ff000000" edBkgCol="0" labelText="Studio Coda Sandbox"
		 editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
		 fontname="Calibri" fontsize="21.0" kerning="0.057" bold="0" italic="0"
		 justification="33"/>
  <LABEL name="new label" id="4445131704e08f8f" memberName="juce__label2"
		 virtualName="" explicitFocusOrder="0" pos="1.628% 5.153% 5.697% 24"
		 edTextCol="ff000000" edBkgCol="0" labelText="1.0.1" editableSingleClick="0"
		 editableDoubleClick="0" focusDiscardsChanges="0" fontname="Calibri"
		 fontsize="12.7" kerning="0.048" bold="0" italic="0" justification="33"/>
  <SLIDER name="SliderAngle2" id="dba9710b659b81f" memberName="juce__slider2"
		  virtualName="" explicitFocusOrder="0" pos="2.442% 16.747% 21.974% 2.576%"
		  thumbcol="ffffffff" textboxtext="ff00ffff" min="0.0" max="360.0"
		  int="0.2" style="LinearHorizontal" textBoxPos="TextBoxRight"
		  textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
		  needsCallback="1"/>
  <SLIDER name="SliderAngle3" id="89c79e4d7ef6f890" memberName="juce__slider3"
		  virtualName="" explicitFocusOrder="0" pos="2.442% 20.612% 21.974% 2.576%"
		  thumbcol="ffffffff" textboxtext="ff00ffff" min="0.0" max="360.0"
		  int="0.2" style="LinearHorizontal" textBoxPos="TextBoxRight"
		  textBoxEditable="1" textBoxWidth="50" textBoxHeight="20" skewFactor="1.0"
		  needsCallback="1"/>
  <SLIDER name="SliderAngleFake1" id="5e5d9e4314141f09" memberName="juce__slider4"
		  virtualName="" explicitFocusOrder="0" pos="3.255% 74.718% 20.346% 2.576%"
		  thumbcol="ffffffff" min="20.0" max="360.0" int="1.0" style="LinearHorizontal"
		  textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="50"
		  textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="SliderAngleFake2" id="2120f82734e0aeec" memberName="juce__slider5"
		  virtualName="" explicitFocusOrder="0" pos="3.255% 78.583% 20.346% 2.576%"
		  thumbcol="ffffffff" min="20.0" max="360.0" int="1.0" style="LinearHorizontal"
		  textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="50"
		  textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="SliderAngleFake3" id="668b274801eacf5d" memberName="juce__slider6"
		  virtualName="" explicitFocusOrder="0" pos="3.255% 82.448% 20.346% 2.576%"
		  thumbcol="ffffffff" min="20.0" max="360.0" int="1.0" style="LinearHorizontal"
		  textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="50"
		  textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <TOGGLEBUTTON name="ButtonActivateFake" id="e9a01a73007848b4" memberName="juce__toggleButton2"
				virtualName="" explicitFocusOrder="0" pos="4.069% 88.889% 4.883% 2.576%"
				buttonText="En" connectedEdges="0" needsCallback="1" radioGroupId="0"
				state="1"/>
  <TEXTBUTTON name="ButtonFakeAngleReset" id="92589f932a76b893" memberName="juce__textButton2"
			  virtualName="" explicitFocusOrder="0" pos="9.766% 88.889% 6.511% 2.576%"
			  bgColOff="ff152525" buttonText="reset" connectedEdges="0" needsCallback="1"
			  radioGroupId="0"/>
  <GROUPCOMPONENT name="new group" id="62e81f78d052b95f" memberName="juce__groupComponent"
				  virtualName="" explicitFocusOrder="0" pos="2.442% 70.853% 22.787% 23.188%"
				  title="Manual Angle"/>
  <TEXTEDITOR name="TextConsole" id="ac3f9febf3a0f322" memberName="juce__textEditor"
			  virtualName="" explicitFocusOrder="0" pos="83.825% 0% 16.277% 100.483%"
			  bkgcol="ff000000" initialText="" multiline="1" retKeyStartsLine="1"
			  readonly="1" scrollbars="0" caret="0" popupmenu="1"/>
  <COMBOBOX name="new combo box" id="83b180716ee5e885" memberName="juce__comboBox"
			virtualName="" explicitFocusOrder="0" pos="26.857% 78.583% 26.857% 5.153%"
			editable="0" layout="33" items="Vivaldi - Winter&#10;Vivaldi - Summer&#10;"
			textWhenNonSelected="Vivaldi - Winter" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="ButtonLoad" id="9e9e552fed105626" memberName="juce__textButton4"
			  virtualName="" explicitFocusOrder="0" pos="55.341% 78.583% 21.16% 5.153%"
			  bgColOff="ff152525" buttonText="LOAD SONG" connectedEdges="0"
			  needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ButtonPlay" id="c670cedfd205634e" memberName="juce__textButton5"
			  virtualName="" explicitFocusOrder="0" pos="66.734% 86.312% 9.766% 7.729%"
			  bgColOff="ff113900" buttonText="PLAY" connectedEdges="0" needsCallback="1"
			  radioGroupId="0"/>
  <TEXTBUTTON name="ButtonLoad" id="9023a65c53adc32e" memberName="juce__textButton6"
			  virtualName="" explicitFocusOrder="0" pos="55.341% 86.312% 9.766% 7.729%"
			  bgColOff="ff152525" buttonText="STOP" connectedEdges="0" needsCallback="1"
			  radioGroupId="0"/>
  <TEXTBUTTON name="ButtonCenter3D" id="1f8cedafdd0f6bfd" memberName="juce__textButton7"
			  virtualName="" explicitFocusOrder="0" pos="17.904% 64.412% 6.511% 2.576%"
			  bgColOff="ff152525" buttonText="CENTER" connectedEdges="0" needsCallback="1"
			  radioGroupId="0"/>
  <TEXTBUTTON name="ButtonFakeAngleCenter" id="e0a1670f81c406d2" memberName="juce__textButton8"
			  virtualName="" explicitFocusOrder="0" pos="17.091% 88.889% 6.511% 2.576%"
			  bgColOff="ff152525" buttonText="save" connectedEdges="0" needsCallback="1"
			  radioGroupId="0"/>
  <TEXTBUTTON name="ButtonPrequelConnect" id="22f8b71662426853" memberName="juce__textButton9"
			  virtualName="" explicitFocusOrder="0" pos="3.255% 64.412% 8.138% 2.576%"
			  bgColOff="ff152525" buttonText="Connect" connectedEdges="0" needsCallback="1"
			  radioGroupId="0"/>
  <SLIDER name="SliderVolume" id="ebf17f54a9548cbd" memberName="juce__slider8"
		  virtualName="" explicitFocusOrder="0" pos="78.128% 68.277% 4.883% 27.053%"
		  thumbcol="ffffffff" min="0.0" max="100.0" int="1.0" style="LinearVertical"
		  textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="50"
		  textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <TEXTBUTTON name="ButtonPresetA" id="b1882e90c36ef4e9" memberName="juce__textButton14"
			  virtualName="" explicitFocusOrder="0" pos="26.857% 86.312% 4.069% 7.729%"
			  bgColOff="ff152525" bgColOn="ffff0000" buttonText="A" connectedEdges="0"
			  needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ButtonPresetC" id="930825aac2fb071d" memberName="juce__textButton13"
			  virtualName="" explicitFocusOrder="0" pos="38.25% 86.312% 4.069% 7.729%"
			  bgColOff="ff152525" bgColOn="ffff0000" buttonText="C" connectedEdges="0"
			  needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ButtonPrequelTest" id="17c198b1f9408eca" memberName="juce__textButton3"
			  virtualName="" explicitFocusOrder="0" pos="12.208% 64.412% 4.883% 2.576%"
			  bgColOff="ff152525" buttonText="Test" connectedEdges="0" needsCallback="1"
			  radioGroupId="0"/>
  <TEXTBUTTON name="ButtonPresetD" id="3e7a0c902f3599d" memberName="juce__textButton10"
			  virtualName="" explicitFocusOrder="0" pos="43.947% 86.312% 4.069% 7.729%"
			  bgColOff="ff152525" bgColOn="ffff0000" buttonText="D" connectedEdges="0"
			  needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ButtonPresetE" id="75e16e4192b44d2d" memberName="juce__textButton12"
			  virtualName="" explicitFocusOrder="0" pos="49.644% 86.312% 4.069% 7.729%"
			  bgColOff="ff152525" bgColOn="ffff0000" buttonText="O" connectedEdges="0"
			  needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

