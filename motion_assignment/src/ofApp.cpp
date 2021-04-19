#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    
    ofBackground(0,0,0);

 
    ofSetFrameRate(60);
//    ofSetWindowTitle("openframeworks");
 

//    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_MULTIPLY);
    
    rectColor = ofColor:: orange;
    drawColor = rectColor;
    
    circleColor = ofColor:: skyBlue;
    drawCircleColor = circleColor;
    
    gui.setup();
    gui.add(floatSlider1.setup("adjust", 0,0,2));
    gui.add(floatSlider2.setup("circles", 0,0,8));
    gui.add(floatSlider3.setup("rectangles", 0,0,70));
    
}
 
//--------------------------------------------------------------
void ofApp::update() {
 
    ofSeedRandom(30);
    
    float animationTime = ofGetElapsedTimef();
            float firstChangeTime = 2;
            float secondChangeTime = 20;
            float thirdChangeTime = 30;
            float fourthChangeTime = 40;

        
        if (animationTime < firstChangeTime) {
                drawColor = rectColor;
            
        } else if (animationTime < secondChangeTime) {
              
              float timeSinceSecond = animationTime - firstChangeTime;
              
              float percentageToSecond = timeSinceSecond / (secondChangeTime - firstChangeTime);
              
              drawColor = rectColor.getLerped(ofColor::skyBlue, percentageToSecond);
            
        } else if (animationTime > thirdChangeTime){
            
            ofColor::skyBlue;
    }
    if (animationTime < firstChangeTime) {

            drawCircleColor = circleColor;
        
    } else if (animationTime < secondChangeTime) {
          
          float timeSinceSecond = animationTime - firstChangeTime;
          
          float percentageToSecond = timeSinceSecond / (secondChangeTime - firstChangeTime);
          
          drawCircleColor = circleColor.getLerped(ofColor::orange, percentageToSecond);
    } else if (animationTime > thirdChangeTime){
        
        ofColor::orange;
    }
}
 
//--------------------------------------------------------------
void ofApp::draw() {
    
    gui.draw();
 
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    
    ofSetLineWidth(3);
    ofNoFill();
    
 
    vector<ofColor> color_list = {drawColor, drawCircleColor};
    for (int i = 0; i < floatSlider2; i++) {
 
        auto radius = 70 + i * 70;
        auto rotate_deg = (ofGetFrameNum() + i * 180) % 360;
        auto rotate_location = glm::vec2(radius * cos(rotate_deg * DEG_TO_RAD), radius * sin(rotate_deg * DEG_TO_RAD));
 
        for (int k = 0; k < color_list.size(); k++) {
 
            auto noise_seed = ofRandom(1000);
 
            ofSetColor(color_list[k]);
            ofBeginShape();
            for (int deg = 0; deg < 360; deg += 1) {
 
                auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
                auto distance = glm::distance(location, rotate_location);
                if (distance < radius * floatSlider1) {
 
                    auto noise_radius = ofMap(ofNoise(noise_seed, location.x * 0.058, location.y * 0.035, ofGetFrameNum() * 0.005), 0, 1, radius - 125, radius + 125);
                    auto noise_location = glm::vec2(noise_radius * cos(deg * DEG_TO_RAD), noise_radius * sin(deg * DEG_TO_RAD));
                    auto gap = location - noise_location;
                    ofVertex(location + gap * ofMap(distance, 0, radius * floatSlider1, 1, 0));
                }
                
                else {
 
                    ofVertex(location);
                }
            }
            ofEndShape(true);
        }
    }
        
    for (int i = 0; i < floatSlider3; i++){
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
        ofRotateDeg(ofGetElapsedTimef());
        ofScale(0.94);
    
    ofSetLineWidth(3);
    ofSetColor(drawColor);
    ofDrawRectangle(0, 0, 850, 850);
        
        }
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
