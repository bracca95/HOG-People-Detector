//
//  VidMan.cpp
//  HOGdetector
//

#include "VidMan.hpp"

VidMan::VidMan(VideoCapture _baseVideo, string _videoPath) {
    baseVideo = _baseVideo;
    videoPath = _videoPath;
    frameCounter = 0;
}

void VidMan::playVideo() {
    
    // try to open video reference
    baseVideo.open(videoPath);
    if (!baseVideo.isOpened()) {
        // throw an exception if there is no video
        throw "no video to display";
        return;
    }
    
    // give a name to a window and open it to display the video
    string window = "Video";
    namedWindow(window, WINDOW_AUTOSIZE);
    
    // frame by frame show: in this case only one frame so that the previous is overwritten
    while (true) {
        frameCounter++;
        
        // put the video frames inside the Mat, which in this case is updated ad every loop (overwrite the previous iteration)
        Mat frame;
        baseVideo >> frame;
        
        // show results in a window
        imshow(window, frame);
        
        // the waitKey's number specifies the time interval between two frames
        // the "waited key" input is 27 (in ASCII) which corresponds to ESC
        char c = (char)waitKey(1);
        if((c==27) || (frameCounter == getTotFrames() - 1)) break;
    }
    
    
    // When everything done, destroy things
    baseVideo.release();
    destroyAllWindows();
    
    return;

}

// print FPS info


// get total number of frames per video
int VidMan::getTotFrames() {
    return baseVideo.get(CAP_PROP_FRAME_COUNT);
}
