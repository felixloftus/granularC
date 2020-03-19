#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    sampleRate 	= 44100;
    bufferSize = 512;

    grainPlayer.setup();
    mixer.addInputFrom(&grainPlayer);

    //SoundStream
    soundStream.listDevices();
	soundStream.setup(this, 2, 2, sampleRate, bufferSize, 4);
	soundStream.setOutput(this);

    //GUI
    gui = new ofxUICanvas();
    gui->setFont("GUI/Fett.ttf");
    gui->addLabel("granular synthesis");
    gui->addSpacer();
    
    gui->addSlider("Speed", -4.0, 4.0, &grainPlayer.speed);
    gui->addSlider("Pitch", 0.0, 10.0, &grainPlayer.pitch);
    gui->addSlider("GrainSize", 0.025, 0.45, &grainPlayer.grainSize);
    gui->addSlider("Overlaps", 1, 5, &grainPlayer.overlaps);
    gui->addSpacer();
    gui->addToggle("Record Input", &grainPlayer.bRecLiveInput);
    gui->addToggle("Set Position", &grainPlayer.bSetPosition);
    gui->addSlider("Position", 0.0, 1.0, &grainPlayer.playHead);
    gui->addSlider("Volume", 0.0, 1.0, &grainPlayer.volume);

    gui->autoSizeToFitWidgets();

    gui->loadSettings("GUI/guiSettings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    grainPlayer.updatePlayHead();
}

//--------------------------------------------------------------
void ofApp::draw(){
    grainPlayer.draw();
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels)
{
    grainPlayer.audioReceived(input,bufferSize,nChannels);
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels)
{
    mixer.audioRequested(output, bufferSize, nChannels);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}


