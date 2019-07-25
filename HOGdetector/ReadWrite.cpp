//
//  ReadWrite.cpp
//  HOGdetector
//

#include "ReadWrite.hpp"

ReadWrite::ReadWrite() {
    
}

// reads the ground truth input file and returns a vector of bounding boxes for every frame
vector<Rect> ReadWrite::getTruth(Mat _frame, int _frameCounter, string _inputTruth) {
    
    ifstream infile (_inputTruth.c_str());
    vector<Rect> correct;
    int fnum, id, posX, posY, dispX, dispY;
    
    // loop the file to read every line. IT MUST BE STRUCTURED LIKE THIS!!
    while (infile >> fnum >> id >> posX >> posY >> dispX >> dispY) {
        if (_frameCounter == fnum) {
            Rect r;
            r.x = posX; r.width = dispX;
            r.y = posY; r.height = dispY;
            
            correct.push_back(r);
        }
    }
    
    infile.close();
    return correct;
}
