//
//  AudioProcessor.h
//  Juce Demo
//
//  Created by Aaron Leese on 5/8/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


/*
 ==============================================================================
 
 This file was auto-generated by the Jucer!
 
 It contains the basic startup code for a Juce application.
 
 ==============================================================================
 */

#ifndef __PLUGINPROCESSOR_H_526ED7A9__
#define __PLUGINPROCESSOR_H_526ED7A9__
 
#include "JuceHeader.h"

#include "AudioPlayer.h"

//==============================================================================
/**
 */
class MainAudioProcessor  : public AudioProcessor
{
    
    AudioSampleBuffer* sampleBuffer;
    
    
public:
    
    AudioPlayer* myAudioPlayerLeft;
    AudioPlayer* myAudioPlayerRight;
    
    float targetBpm;
    
    //==============================================================================
    MainAudioProcessor();
    ~MainAudioProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();
    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    void reset();
    
    //==============================================================================
    bool hasEditor() const                  { return true; }
    AudioProcessorEditor* createEditor();
    
    //==============================================================================
    const String getName() const            { return "name of it"; }
    
    int getNumParameters();
    float getParameter (int index);
    void setParameter (int index, float newValue);
    const String getParameterName (int index);
    const String getParameterText (int index);
    
    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;
    
    bool acceptsMidi() const;
    bool producesMidi() const;
    
    //==============================================================================
    int getNumPrograms()                                                { return 0; }
    int getCurrentProgram()                                             { return 0; }
    void setCurrentProgram (int /*index*/)                              { }
    const String getProgramName (int /*index*/)                         { return String::empty; }
    void changeProgramName (int /*index*/, const String& /*newName*/)   { }
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
    
    //==============================================================================
    // These properties are public so that our editor component can access them
    // A bit of a hacky way to do it, but it's only a demo! Obviously in your own
    // code you'll do this much more neatly..
    
    // this keeps a copy of the last set of time info that was acquired during an audio
    // callback - the UI component will read this and display it.
    AudioPlayHead::CurrentPositionInfo lastPosInfo;
     
    
private:
    //==============================================================================
     
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainAudioProcessor);
};

#endif  // __PLUGINPROCESSOR_H_526ED7A9__
