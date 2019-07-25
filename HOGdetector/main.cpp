//
//  main.cpp
//  HOGdetector
//

#include <iostream>
#include "VidMan.hpp"

int main(int argc, const char * argv[]) {
    
    Mat frame;
    VideoCapture cap;
    string prova = "/Users/bracca/Documents/Progetti/ComputerVision_Project/CPP_DATASET/Datasets/ETH/BAHNHOF/ETH-Bahnhof.mp4";
    string verit = "/Users/bracca/Documents/Progetti/ComputerVision_Project/CPP_DATASET/Datasets/ETH/BAHNHOF/gt/gt_output.txt";
    
    VidMan vidan = VidMan(frame, cap, prova, verit);
    
    // open a video
    try {
        // write "niente" for GT if do not want it
        vidan.playVideo();
    } catch (const char* err_msg) {
        cerr << "unable to retrieve or to show video. Quitting program" << endl;
    }
    
    return 0;
}
