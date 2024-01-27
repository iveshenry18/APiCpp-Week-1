#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (1600, 900);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    // (statically) Hello
    juce::Font helloFont =juce::Font (juce::Font::getDefaultMonospacedFontName(), 128.0, juce::Font::bold);
    juce::String helloText = "Hello. ";
    auto helloWidth = helloFont.getStringWidth(helloText);
    int leftPaddingWidth = 10;
    auto helloBounds = getLocalBounds();
    helloBounds.setLeft(helloBounds.getX() + leftPaddingWidth);
    
    g.setFont (helloFont);
    g.setColour (juce::Colours::white);
    g.drawText (helloText, helloBounds, juce::Justification::centredLeft, true);
    
    // (dramatically) World
    auto worldBounds = getLocalBounds();
    worldBounds.setLeft(worldBounds.getX() + leftPaddingWidth + helloWidth);
    
    g.setFont(juce::Font(juce::Font::getDefaultSerifFontName(), 128.0, juce::Font::italic));
    g.setColour (juce::Colours::lightcyan);
    g.drawText ("World.", worldBounds, juce::Justification::centredLeft, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
