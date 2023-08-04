#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetColor(0, 255, 128, 32);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_SUBTRACT);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clear();

	float size = 1;
	for (float x = 80; x <= ofGetWidth() - 80; x += size) {

		for (float y = 80; y <= ofGetHeight() - 80; y += size) {

			if (glm::distance(glm::vec2(x, y), ofGetWindowSize() * 0.5) < 300) {

				float deg = ofMap(ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.01), 0, 1, -1800, 1800);
				this->mesh.addVertex(glm::vec3(x + size * 3 * cos(deg * DEG_TO_RAD), y + size * 3 * sin(deg * DEG_TO_RAD), ofMap(abs(deg), 0, 360, 0, 150)));
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofTranslate(ofGetWindowSize() * -0.5);

	this->mesh.drawVertices();

	this->cam.end();
}


//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}