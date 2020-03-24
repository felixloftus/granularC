#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    sampleRate 	= 44100;
    bufferSize = 512;

    I.setup();
//    andI.setup();
    andIandI.setup();
    chunky.push_back(I);
//    chunky.push_back(andI);
    chunky.push_back(andIandI);
    
    // is the problem something about not doing chunky.size-1?
//    or just about not having setup the wholething?
    for (int i=0; i<chunky.size(); i++) {
        mixer.addInputFrom(&chunky[i]);
    }

    //SoundStream
    soundStream.listDevices();
	soundStream.setup(this, 2, 2, sampleRate, bufferSize, 4);
	soundStream.setOutput(this);
    
    gloSpeed = 0.5;
    for (int i=0; i<chunky.size(); i++) {
        chunky[i].speed=gloSpeed;
        chunky[i].pitch=0.2+(i+1)/chunky.size();
        chunky[i].grainSize=0.35;
        chunky[i].overlaps=5;
    }

//    //GUI
    gui = new ofxUICanvas();
    gui->setFont("GUI/Fett.ttf");
    gui->addLabel("granular synthesis");
    gui->addSpacer();
 
//    gui->addSlider("Speed", -4.0, 4.0, &I.speed);
//    gui->addSlider("Pitch", 0.0, 10.0, &I.pitch);
//    gui->addSlider("GrainSize", 0.025, 0.45, &andI.grainSize && &andI.grainSize);
//    gui->addSlider("Overlaps", 1, 5, &andI.overlaps);
//    gui->addSlider("Overlap2s", 1, 5, &andI.overlaps);
    gui->addSpacer();
    gui->addToggle("Record Input", &I.bRecLiveInput);
//    gui->addToggle("Record Inpu2t", &andI.bRecLiveInput);
    gui->addToggle("Record Inpu2t", &andIandI.bRecLiveInput);
//    gui->addToggle("Set Position", &I.bSetPosition);
//    gui->addToggle("Set Position 2", &andI.bSetPosition);
//    gui->addSlider("Position2", 0.0, 1.0, &andI.playHead);
//    gui->addSlider("Position", 0.0, 1.0, &I.playHead);
    gui->addSlider("Volume", 0.0, 1.0, &I.volume);
//    gui->addSlider("Volume2", 0.0, 1.0, &andI.volume);
    gui->addSlider("Volume3", 0.0, 1.0, &andIandI.volume);
    


    gui->autoSizeToFitWidgets();

    gui->loadSettings("GUI/guiSettings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<chunky.size();i++){
        chunky[i].updatePlayHead();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    I.draw();
//    andI.draw();
    andIandI.draw();
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels)
{
    I.audioReceived(input,bufferSize,nChannels);
//    andI.audioReceived(input, bufferSize, nChannels);
    andIandI.audioReceived(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels)
{
    mixer.audioRequested(output, bufferSize, nChannels);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT){
        // change bRecLiveInput
        for(int i=0;i<chunky.size();i++){
//            chunky[i].bRecLiveInput=!chunky[i].bRecLiveInput;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}


