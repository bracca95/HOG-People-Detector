//
//  Detector.cpp
//  HOGdetector
//

#include "Detector.hpp"

Detector::Detector() {
    // ask the user to select the mode, either DEFAULT or DAIMLER
    toggleMode();
    
    // DEFAULT mode selected
    if (triggerMode == 0) {
        m = DEFAULT;
        // default descriptor, no parameters needed
        hog = HOGDescriptor();
        // set coefficients for the linear SVM classifier, here the ones trained for DEFAULT WINDOW SIZE people detection
        hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    }
    
    // DAIMLER mode selected
    if (triggerMode == 1) {
        m = DAIMLER;
        //HOGDescriptor(winSize(64, 128), blockSize(16,16), blockStride, cellSize(8,8), nBins=9)
        hog_d = HOGDescriptor(Size(48, 96), Size(16, 16), Size(8, 8), Size(8, 8), 9);
        // set coefficients for the linear SVM classifier, here the ones trained for (48,96) WINDOW SIZE people detection https://bit.ly/2qDnQWg
        hog_d.setSVMDetector(HOGDescriptor::getDaimlerPeopleDetector());
    }
    
}

// switch between the two modes
void Detector::toggleMode() {
    do {
        cout << "select mode (default (0), daimler (1)): ";
        scanf("%d", &triggerMode);      // use scanf so that it is clearly an integer (%d)
    } while ( (triggerMode != 0) && (triggerMode != 1) );
}

// returns the name of the mode in use
string Detector::modeName() const {
    if (m == DEFAULT) return "Default";
    else return "Daimler";
}

// Run the detector with default parameters. To get a higher hit-rate
// (and more false alarms, respectively), decrease the hitThreshold and
// groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
vector<Rect> Detector::detect(InputArray img) {
    vector<Rect> found;
    if (m == DEFAULT)
        // detectMultiScale(img, vector<Rect>, hit_threshold=0, win_strideSize, paddingSize=1.05, scale=2, group_threshold=2)
        hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2, false);
    // detectMultiScale performs object detection with a multi-scale window.
    else if (m == DAIMLER)
        // detectMultiScale(img, vector<Rect>, hit_threshold=0, win_strideSize, paddingSize, scale, group_threshold=2)
        hog_d.detectMultiScale(img, found, 0.5, Size(8,8), Size(32,32), 1.05, 2, true);
    
    return found;
}
