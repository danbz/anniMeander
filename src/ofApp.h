#pragma once

#include "ofMain.h"

/*
 Project Title: anniMeander
 Description: a quick investigation of red meander by anni albers https://www.wikiart.org/en/anni-albers colours taken from the textile woven version.
 
 ©Daniel Buzzo 2019
 dan@buzzo.com
 http://buzzo.com
 https://github.com/danbz
 */


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void meander();
		
    int boxSize, rows, columns;
    vector<ofColor> colorOrder;
    ofColor redCol, yellowCol;
    
};
