//
//  main.cpp
//  HOGdetector
//
//  Created by Lorenzo Braccaioli on 24/07/2019.
//  Copyright © 2019 bracca. All rights reserved.
//

#include <iostream>
#include "VidMan.hpp"

int main(int argc, const char * argv[]) {
    
    string prova = "/Users/bracca/Documents/Progetti/ComputerVision_Project/CPP_DATASET/Datasets/ETH/BAHNHOF/ETH-Bahnhof.mp4";
    VidMan vidan = VidMan(prova);
    
    try {
        vidan.displayVideo();
    } catch (const char* err_msg) {
        cerr << "unable to retrieve or to show video. Quitting program" << endl;
    }
    
    return 0;
}
