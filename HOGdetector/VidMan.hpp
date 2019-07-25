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

using namespace std;
using namespace cv;

class VidMan {
    
private:
    Mat frame;
    VideoCapture baseVideo;
    string videoPath;
    int frameCounter;
    
public:
    // constructors
    VidMan(Mat _frame, VideoCapture _baseVideo, string _videoPath);
    
    // methods
    void playVideo();
    void printFPS(Mat _frame);
    int getTotFrames();
    
};

#endif /* VidMan_hpp */
