//
//  ReadWrite.hpp
//  HOGdetector
//

#ifndef ReadWrite_hpp
#define ReadWrite_hpp

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

class ReadWrite {
private:
    string inputTruth;
    
public:
    ReadWrite();
    vector<Rect> getTruth(Mat _frame, int _frameCounter, string _inputTruth);
    void writeOnFile(ofstream* _outfile, int _frameCounter, double _precision, double _recall);
    void openFile(ofstream* _outfile, string _inputTruth);
    void closeFile(ofstream* _outfile);
};

#endif /* ReadWrite_hpp */
