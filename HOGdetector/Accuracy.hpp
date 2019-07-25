//
//  Accuracy.hpp
//  HOGdetector
//

#ifndef Accuracy_hpp
#define Accuracy_hpp

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include "ReadWrite.hpp"

using namespace std;
using namespace cv;

class Accuracy {
private:
    int truePositive, falsePositive, falseNegative;
    double precision, recall;
    ReadWrite writer;
    
public:
    // constructor(s)
    Accuracy();
    
    // methods
    void getAccuracy(vector<Rect> _found, vector<Rect> _truth, ofstream* _outfile, int _frameCounter);
    int overlap(Rect _rect1, Rect _rect2);
};

#endif /* Accuracy_hpp */
