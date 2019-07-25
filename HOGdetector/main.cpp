//
//  main.cpp
//  HOGdetector
//

#include <iostream>
#include "VidMan.hpp"

int main(int argc, const char * argv[]) {
    
    const char* keys = {
        "{help h|     | show help message}"
        "{vf    |     | path of video file}"
        "{gt    |     | path of ground truth txt file}"
    };
    
    CommandLineParser parser( argc, argv, keys );
    
    if (parser.has("help")) {
        parser.printMessage();
        cout << "Sample usage: " << endl
             << "./target -vf='/path/to/video/file.mp4' "
             << "-gt='/path/to/groundtruth.txt' " << endl << endl
             << "-gt='' If no ground truth available" << endl;
        exit(0);
    }
    
    string video = parser.get<string> ("vf");
    string grndt = parser.get<string> ("gt");
    Mat frame;
    VideoCapture cap;
    
    VidMan vidman = VidMan(frame, cap, video, grndt);
    
    // open a video
    try {
        // write "niente" for GT if do not want it
        vidman.playVideo();
    } catch (const char* err_msg) {
        cerr << "unable to retrieve or to show video. Quitting program" << endl;
    }
    
    return 0;
}
