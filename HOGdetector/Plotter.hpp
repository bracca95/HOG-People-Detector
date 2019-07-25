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
#include <fstream>

using namespace std;
using namespace cv;

class Plotter {
private:
    Mat frame;
    vector<Rect> boundBoxes;
    bool gt;                    // if true-> GT, if false -> detection
    
public:
    // constructor(s)
    Plotter();
    Plotter(Mat _frame);
    
    // methods
    void plotBoxes(Mat _frame, vector<Rect> _boundBoxes, bool _gt);
    void adjustRect(Rect &r) const;
};

#endif /* Plotter_hpp */
