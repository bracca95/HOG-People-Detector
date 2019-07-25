//
//  VidMan.cpp
//  HOGdetector
//

#include "VidMan.hpp"

VidMan::VidMan(Mat _frame, VideoCapture _baseVideo, string _videoPath, string _inputTruth) {
    frame = _frame;
    baseVideo = _baseVideo;
    videoPath = _videoPath;
    inputTruth = _inputTruth;
    frameCounter = 0;
    
    plot = Plotter(_frame);
}

void VidMan::playVideo() {
    
    // try to open video reference
    baseVideo.open(videoPath);
    if (!baseVideo.isOpened()) {
        // throw an exception if there is no video
        throw "no video to display";
        return;
    }
    
    // open file to save data
    ofstream outfile;
    if (inputTruth != "")
        readwrite.openFile(&outfile, inputTruth);
    
    // give a name to a window and open it to display the video
    string window = "Video";
    namedWindow(window, WINDOW_AUTOSIZE);
    
    // frame by frame show: in this case only one frame so that the previous is overwritten
    while (true) {
        // put the video frames inside the Mat, which in this case is updated ad every loop (overwrite the previous iteration)
        frameCounter++;
        baseVideo >> frame;
        printFPS(frame);
        
        // start and plot detection
        found = detector.detect(frame);
        plot.plotBoxes(frame, found, false);
        
        // ground truth: plot and compute accuracy
        if (inputTruth != "") {
            // plot ground truth
            truth = readwrite.getTruth(frame, frameCounter, inputTruth);
            plot.plotBoxes(frame, truth, true);
            
            // accuracy
            accuracy.getAccuracy(found, truth, &outfile, frameCounter);
        }
        
        // show results in a window
        imshow(window, frame);
        
        // the waitKey's number specifies the time interval between two frames
        // the "waited key" input is 27 (in ASCII) which corresponds to ESC
        char c = (char)waitKey(0);
        if((c==27) || (frameCounter == getTotFrames() - 1)) break;
    }
    
    
    // When everything done, destroy things
    baseVideo.release();
    destroyAllWindows();
    readwrite.closeFile(&outfile);
    
    return;
}

// print FPS info
void VidMan::printFPS(Mat _frame) {
    ostringstream buf;
    buf << "Frame Count: " << frameCounter;
    putText(_frame, buf.str(), Point(10, 30), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255), 2, LINE_AA);
}

// get current frame
int VidMan::getCurFrame() {
    return frameCounter;
}

// get total number of frames per video
int VidMan::getTotFrames() {
    return baseVideo.get(CAP_PROP_FRAME_COUNT);
}
