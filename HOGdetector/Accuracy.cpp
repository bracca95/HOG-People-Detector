//
//  Accuracy.cpp
//  HOGdetector
//

#include "Accuracy.hpp"

Accuracy::Accuracy() {
    truePositive = 0;
    falsePositive = 0;      // all detections - true positives
    falseNegative = 0;      // all _truths - true positives
    precision = 0.0;
    recall = 0.0;
}

// Accuracy is computed as precision and recall
void Accuracy::getAccuracy(vector<Rect> _found, vector<Rect> _truth, ofstream* _outfile, int _frameCounter) {
    
    // here to count the TRUE POSITIVE
    for (vector<Rect>::iterator i = _found.begin(); i != _found.end(); ++i) {
        for (vector<Rect>::iterator j = _truth.begin(); j != _truth.end(); ++j) {
            int a1 = i->area();
            int a2 = j->area();
            int ovl = overlap(*i, *j);
            if ( ((double)ovl / (((double)a1 + (double)a2)/(double)2)) > 0.5 ) {
                // compute all the true positive
                truePositive++;
            }
        }
        
        // check for any errors
        if (_found.size() < truePositive) {
            truePositive = (int)_found.size();
        }
        
        // compute false positive and false negative
        falsePositive = (int)_found.size() - truePositive;
        falseNegative = (int)_truth.size() - truePositive;
    }
    
    // compute precision and recall
    precision = (double)truePositive / ((double)truePositive + (double)falsePositive);
    recall = (double)truePositive / ((double)truePositive + (double)falseNegative);
    
    // DEBUG
    //cout << "guess: " << truePositive << ". size: " << _found.size() << endl;
    writer.writeOnFile(_outfile, _frameCounter, precision, recall);
}

int Accuracy::overlap(Rect _rect1, Rect _rect2) {
    int dx, dy;
    
    dx = min( (_rect1.x + _rect1.width), (_rect2.x + _rect2.width) ) - max( _rect1.x, _rect2.x );
    dy = min( (_rect1.y + _rect1.height), (_rect2.y + _rect2.height)) - max( _rect1.y, _rect2.y );
    
    if ((dx >= 0) && (dy >= 0))
        return dx*dy;
    else
        return 0;
}
