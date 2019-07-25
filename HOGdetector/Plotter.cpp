//
//  Plotter.cpp
//  HOG
//

#include "Plotter.hpp"

Plotter::Plotter() {
    
}

Plotter::Plotter(Mat _frame) {
    frame = _frame;
}

// plot the bounding boxes found by Detector or Ground truth
void Plotter::plotBoxes(Mat _frame, vector<Rect> _boundBoxes, bool _gt) {
    vector<Rect>::iterator i;
    
    for (i = _boundBoxes.begin(); i != _boundBoxes.end(); ++i) {
        Rect &r = *i;
        
        if (_gt == false) {
            adjustRect(r);
            rectangle(_frame, r.tl(), r.br(), Scalar(0, 255, 0), 2);
        } else {
            rectangle(_frame, r.tl(), r.br(), Scalar(255, 0, 0), 2);
        }
    }
}

// The HOG detector returns slightly larger rectangles than the real objects,
// so we slightly shrink the rectangles to get a nicer output.
void Plotter::adjustRect(Rect &r) const {
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);
}
