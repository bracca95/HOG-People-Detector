//
//  Detector.hpp
//  HOGdetector
//

#ifndef Detector_hpp
#define Detector_hpp

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace cv;

class Detector {
    
private:
    enum Mode { DEFAULT, DAIMLER } m;
    HOGDescriptor hog, hog_d;
    int triggerMode;
    
public:
    // zero parameter constructor
    Detector();
    
    // methods
    void toggleMode();
    string modeName() const;
    vector<Rect> detect(InputArray img);
    void adjustRect(Rect &r) const;
};

#endif /* Detector_hpp */
