#include "ofApp.h"


// a quick investigation of red meander by anni albers https://www.wikiart.org/en/anni-albers
// colours taken from the textile woven version
// dan buzzo 30/12/2018

//--------------------------------------------------------------
void ofApp::setup(){
    boxSize =40;
    meander();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int col =0;
       for (int i=0; i< ofGetHeight()-boxSize; i+=boxSize){
        for (int j=0; j< ofGetWidth()-boxSize; j+=boxSize) {
            ofSetColor( colorOrder[col] );
            ofDrawRectangle(j, i, boxSize,  boxSize);
            col ++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            meander();
            break;
            
        case 'f':
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::meander(){
    int col =0;
    colorOrder.clear();
    ofColor newColor;
    for (int i=0; i< ofGetHeight()-boxSize; i+=boxSize){
        for (int j=0; j< ofGetWidth()-boxSize; j+=boxSize) {
            if (ofRandom(1)<0.5){
                newColor.set(210 , 70, 14); // from anni albers 'red meander'
            } else {
                newColor.set(206 , 210, 156);
            }
            colorOrder.push_back(newColor);
            ofDrawRectangle(j, i, boxSize,  boxSize);
        }
    }
}
