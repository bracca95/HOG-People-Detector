//
//  main.cpp
//  HOGdetector
//

#include <iostream>
#include "VidMan.hpp"

// header
void printUsage ();

/* --- MAIN  --- */
int main(int argc, const char * argv[]) {
    
    /* PARSER */
    const char* keys = {
        "{help h|     | show help message}"
        "{vf    |     | path of video file}"
        "{gt    |     | path of ground truth. Omit if not exists}"
    };
    
    CommandLineParser parser(argc, argv, keys);
    
    if (parser.has("help")) {
        parser.printMessage();
        printUsage();
        exit(0);
    }
    
    /* EXEC */
    Mat frame;
    VideoCapture cap;
    string video = parser.get<string> ("vf");
    string grndt = parser.get<string> ("gt");
    
    VidMan vidman = VidMan(frame, cap, video, grndt);
    
    // open a video
    try {
        vidman.playVideo();
    } catch (const char* err_msg) {
        cerr << "Cannot retrieve or show video. Quitting program" << endl;
        printUsage();
    }
    
    return 0;
} /* end-of main.cpp */


// print usage function
void printUsage () {
    cout << "Sample usage: " << endl
    << "(1) ./target -vf='/path/to/video/file.mp4' " << "-gt='/path/to/groundtruth.txt' " << endl
    << "(2) ./target -vf='/path/to/video/file.mp4'" << endl;
}
