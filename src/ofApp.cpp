#include "ofApp.h"

/*
 Project Title: anniMeander
 Description: a quick investigation of red meander by anni albers https://www.wikiart.org/en/anni-albers colours taken from the textile woven version.
 
 ©Daniel Buzzo 2019
 dan@buzzo.com
 http://buzzo.com
 https://github.com/danbz
 */

//--------------------------------------------------------------
void ofApp::setup(){
    boxSize =40;
    // colors taken from anni albers 'red meander' textile version
    redCol.set(210 , 70, 14);
    yellowCol.set(206 , 210, 156);
    columns = ofGetWidth()/ boxSize;
    rows = ofGetHeight()/boxSize;
    
    meander();

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int col =0;
    for (int i=0; i< rows; i++){
        for (int j=0; j< columns; j++) {
            ofSetColor( colorOrder[col] );
            ofDrawRectangle(j*boxSize, i*boxSize, boxSize,  boxSize);
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
    // create a red or white meander by choosing colors in red or white to put into vector for width x height
    // TBD add in logic to create continuous paths of red and white with context sensitivity to other blocks around each new block ?
    // TBD make markov chain like probability for edges and bifurcations?
    colorOrder.clear();
    ofColor newColor;
    int col = 0;
    for (int i=0; i< rows; i++){
        for (int j=0; j< columns; j++) {
            if ((i==0) or (i == rows-1) or (j==0) or (j== columns-1) ){
                
                if (ofRandom(1)>0.1){ // make red more likely at a screen border
                    newColor=redCol;
                } else {
                    newColor=yellowCol;
                }
            } else {
                
                if (ofRandom(1) < 0.5 ){
                    newColor = redCol;
                } else {
                    
                    newColor = yellowCol;
                    
                     newColor.set(0 , 210, 200);
                }
            }
            colorOrder.push_back(newColor);
            cout << "push" << newColor << endl;
            ofDrawRectangle(j, i, boxSize,  boxSize);
            col++;
        }
    }
}
