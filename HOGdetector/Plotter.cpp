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

// plot the bounding boxes found by Detector
void Plotter::plotBoxes(Mat _frame, vector<Rect> _boundBoxes) {
    vector<Rect>::iterator i;
    
    for (i = _boundBoxes.begin(); i != _boundBoxes.end(); ++i) {
        Rect &r = *i;
        adjustRect(r);
        rectangle(_frame, r.tl(), r.br(), Scalar(0, 255, 0), 2);
    }
}

// reads the ground truth input file and plot it
vector<Rect> Plotter::plotTruth(Mat _frame, int _frameCounter, string _inputTruth) {
    
    ifstream infile (_inputTruth.c_str());
    vector<Rect> correct;
    int fnum, id, posX, posY, dispX, dispY;
    
    while (infile >> fnum >> id >> posX >> posY >> dispX >> dispY) {
        if (_frameCounter == fnum) {
            Rect r;
            r.x = posX; r.width = dispX;
            r.y = posY; r.height = dispY;
            
            correct.push_back(r);
            rectangle(_frame, r.tl(), r.br(), Scalar(255,0,0));
        }
    }
    infile.close();
    
    return correct;
}

// The HOG detector returns slightly larger rectangles than the real objects,
// so we slightly shrink the rectangles to get a nicer output.
void Plotter::adjustRect(Rect &r) const {
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);
}
