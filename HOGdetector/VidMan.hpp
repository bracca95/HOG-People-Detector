//
//  VidMan.hpp
//  HOGdetector
//

#ifndef VidMan_hpp
#define VidMan_hpp

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include "Detector.hpp"
#include "Plotter.hpp"
#include "ReadWrite.hpp"

using namespace std;
using namespace cv;

class VidMan {
    
private:
    /* own attributes */
    Mat frame;
    VideoCapture baseVideo;
    string videoPath, inputTruth;
    int frameCounter;
    
    /* derived */
    Detector detector;
    vector<Rect> found, truth;
    Plotter plot;
    ReadWrite readwrite;
    
public:
    // constructors
    VidMan(Mat _frame, VideoCapture _baseVideo, string _videoPath, string _inputTruth);
    
    // methods
    void playVideo();
    void printFPS(Mat _frame);
    int getTotFrames();
    int getCurFrame();
    
};

#endif /* VidMan_hpp */
