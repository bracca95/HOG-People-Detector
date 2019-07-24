//
//  VidMan.hpp
//  HOGdetector
//
//  Created by Lorenzo Braccaioli on 24/07/2019.
//  Copyright © 2019 bracca. All rights reserved.
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
    static int frameCount, totNumFrames;
    Mat frame;
    VideoCapture baseVideo;
    string videoPath;
    
public:
    VidMan ();
    VidMan (string videoPath);
    
    void displayVideo ();
    
    // frame counter
    int setFrameCount ();
    int getFrameCount ();
    int totFrames ();
    
};

#endif /* VidMan_hpp */
