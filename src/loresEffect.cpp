//
//  loresEffect.cpp
//
//  Fefe
//
//

#include "loresEffect.h"

//--------------------------------------------------------------
void loresFilter::setSampleRate( int rate )
{
	sampleRate = rate;
}

//--------------------------------------------------------------
void loresFilter::setup(){
    
    volume = 0.5;
    sampleRate 	= 44100;
    bufferSize = 512;
    
    //Maxi
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
}

////--------------------------------------------------------------
//void loresFilter::audioRequested (float *output, int numFrames, int nChannels)
//{
//    for (int i = 0; i < bufferSize; i++)
//    {
//
//        wave = ps->play(pitch, speed, grainSize, (int)overlaps);
//        mymix.stereo(wave, outputs, 0.5);
//        output[i*nChannels    ] = outputs[0] * volume;
//        output[i*nChannels + 1] = outputs[1] * volume;
//    }
//}

////--------------------------------------------------------------
//void GrainPlayer::drawWaveform(){
//    // this mostly makes sense
//    ofSetColor(255);
//    ofFill();
//    
//    const float waveformWidth  = ofGetWidth() - 40;
//    const float waveformHeight = 300;
//    
//    float top = ofGetHeight() - waveformHeight - 20;
//    float left = 20;
//    
//    // draw the audio waveform
//    for(int i= 0; i < LENGTH; i+=bufferSize){
//        // mapping the length of the sample to the width of the wave
//        curXpos = ofMap(i,0,LENGTH,left,waveformWidth+20);
//        // not too sure what is happening in the Y - 32768 must be the maximum height of the recording - is this specific to the user?
//        curYpos = ofMap(samp.temp[i],-32768,32768,top,waveformHeight+top);
//        ofSetColor(ofColor::yellow);
//        ofEllipse(curXpos, curYpos, 2, 2);
//        ofLine(curXpos, curYpos, prevXpos, prevYpos);
//        if(i < LENGTH-bufferSize){
//            prevXpos = curXpos;
//            prevYpos = curYpos;
//        } else {
//            prevXpos = left;
//            prevYpos = waveformHeight+top;
//        }
//    }
//    
//    // draw a playhead over the waveform
//    ofSetColor(ofColor::white);
//    ofLine(left + ps->getNormalisedPosition() * waveformWidth, top, left + ps->getNormalisedPosition() * waveformWidth, top + waveformHeight);
//    ofDrawBitmapString("PlayHead", left + ps->getNormalisedPosition() * waveformWidth-69, top+30);
//
//    
//    // Draw Current Recording Position
//    float sampRecPerc = (float)samp.recordPosition / (float)LENGTH;
//    ofSetColor(ofColor::red);
//    ofLine(left + sampRecPerc * waveformWidth, top, left + sampRecPerc * waveformWidth, top + waveformHeight);
//    ofDrawBitmapString("RecPos", left + sampRecPerc * waveformWidth-52, top+15);
//    
//    // draw a frame around the whole thing
//    ofSetColor(ofColor::white);
//    ofNoFill();
//    ofRect(left, top, waveformWidth, waveformHeight);
//}
//
//
//
