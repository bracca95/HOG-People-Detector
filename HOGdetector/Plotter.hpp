//
//  Plotter.hpp
//  HOG
//

#ifndef Plotter_hpp
#define Plotter_hpp

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class Plotter {
private:
    Mat frame;
    vector<Rect> boundBoxes;
    
public:
    // constructor(s)
    Plotter();
    Plotter(Mat _frame);
    
    // methods
    void plotBoxes(Mat _frame, vector<Rect> _boundBoxes);
    void adjustRect(Rect &r) const;
};

#endif /* Plotter_hpp */
