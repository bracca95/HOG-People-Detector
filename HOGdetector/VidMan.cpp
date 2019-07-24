//
//  VidMan.cpp
//  HOGdetector
//
//  Created by Lorenzo Braccaioli on 24/07/2019.
//  Copyright © 2019 bracca. All rights reserved.
//

#include "VidMan.hpp"

VidMan::VidMan () {
    frameCount = 0;
    frame = NULL;
    baseVideo = NULL;
    videoPath = "";
}

VidMan::VidMan (string _videoPath) {
    frameCount = 0;
    frame = Mat();
    baseVideo = VideoCapture();
    videoPath = _videoPath;
}

void VidMan::displayVideo () {
    // try to open video: throw an exception if wrong path
    baseVideo.open(videoPath);
    if (!baseVideo.isOpened()) {
        throw "no video to display";
        return;
    }
    
    // give a name to a window and open it to display the video
    string window = "Video";
    namedWindow(window, WINDOW_AUTOSIZE);
    
    while (true) {
        int frameCounter = setFrameCount();
        
        // show results in a window
        baseVideo >> frame;
        imshow(window, frame);
        
        // the waitKey's number specifies the time interval between two frames
        // the "waited key" input is 27 (in ASCII) which corresponds to ESC
        char c = (char)waitKey(1);
        if((c==27) || (frameCounter == totNumFrames - 1)) break;
    }
    
    // When everything done, destroy things
    baseVideo.release();
    destroyAllWindows();
    
    return;
}

int VidMan::setFrameCount() {
    int frameC = getFrameCount();
    return frameCount = frameC + 1;
}

int VidMan::getFrameCount() {
    return frameCount;
}

int VidMan::totFrames () {
    return totNumFrames = baseVideo.get(CAP_PROP_FRAME_COUNT);
}
