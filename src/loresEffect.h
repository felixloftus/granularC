//
//  loresEffect.h
//
//  Fefe
//
//

#pragma once


#include "ofSoundUnit.h"
#include "ofSoundEffect.h"
#include "ofMain.h"
#include "ofxMaxim.h"
#include "maximilian.h"
#include <sys/time.h>
//
//typedef hannWinFunctor grainPlayerWin;
//
//#define LENGTH 294000
//
class loresFilter : public ofSoundEffect{
   public:
        void setup();
        void draw();
        void setSampleRate( int rate );
        void audioRequested (float *output, int numFrames, int nChannels);
        void process( float* input, float *output, int numFrames, int numInChannels, int numOutChannels );
    
        int sampleRate;
        float volume;
        int bufferSize;
    
        maxiFilter resonate;
        double me, andMe;
        double outputs[2];
};
//
//public:
//    void setup();
//    void draw();
//
//    void drawWaveform();
//
//	void audioReceived(float *input, int bufferSize, int nChannels);
//    void audioRequested (float *output, int numFrames, int nChannels);
//    void setSampleRate( int rate );
//	string getName() { return "soundSourceMaxiGrains"; }
//
//    //Bool event for Recording Toggle/ resets play position relative to current Rec position
//    void updatePlayHead();
//    bool bUpdatePlayheadEvent;
//
//    int bufferSize;
//	int	sampleRate;
//	float volume;
//
//    //////////// ofxMaxim ////////////
//    maxiPitchStretch<grainPlayerWin> *ps;
//    maxiMix mymix;
//    maxiSample samp;
//    double wave, waveFilt;
//    double outputs[2];
//    double windowAmp;
//
//    //Recording
//    bool bSetPosition;
//    bool bRecLiveInput;
//    float recMix;
//
//
//    //Grain Variables
//    float speed;
//    float grainSize;
//    float pitch;
//    float playHead;
//    float overlaps;
//
//    //Drawing
//    int curXpos, curYpos;
//    int prevXpos, prevYpos;
//
//};
