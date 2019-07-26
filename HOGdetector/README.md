# HOG People Detector

The program uses a HOG people detector trained on s SVM classifier to draw a rectangle that aims to identify the people in the video frame by frame.
The video is passed as input to the program and the algorithm can be run only for one instance; if you need to perform the same operation on other video, please modify the full path accordingly.

As the program starts, the user is asked to choosed between to main methods:
  - DEFAULT
  - DAIMLER

The first uses the default window size, as explained in the original paper (Dalal, Triggs[1]), while the daimler mode uses a SVM trained on humand, over a (48,96) window.
The mode is selected by simply pressing "0" (default) or "1" (daimler) as soon as the program is run.

# 1) Compile OpenCV
The first thing you need is a compiled version of OpenCV (I am using 3.4.3). Refer to an OpenCV installation guide for your architecture.

# 2) IDE
Any IDEs can be used to read/write the program. Some OpenCV libraries may be required to correctly interpret commands.
Header libraries are found in /usr/local/include.
Library files are found in /usr/local/lib.

# 3) Build the program
To build the program, move into the main (highest) project *HOGdetector* directory and run the `compile.sh` script. 
Customizations might be required to compile properly.

Some existing code has been used to write this program[2][3]

# 4) Usage
A directory called `build` will appear after building. Open a terminal in the location of the executable and run:

    ./target -h

to understand how to use it. You can simply pass a video, or you can arbitrarily choose to provide also a ground truth file. In the latter case, the overall accuracy of the performed detection is computed.

# Important note
If you are going to provide a ground truth file, it must follow some strict rules:

 - it must be a text file (or no extension);
 - frames must start from `fnum >= 1`;
 - values must be separated by tabs.

Example:

    fnum	id	posX	posY	dispX	dispY
where:

 - `fnum` = frame number
 - `id` = person id
 - `posX` = top right corner of the bounding box on the x-axis (pixel)
 - `posY` = top right corner of the bounding box on the y-axis (pixel)
 - `dispX` = length of the bounding box on the x-axis (pixel)
 - `dispY` = length of the bounding box on the y-axis (pixel)

# Additional notes
The accuracy has been computed as suggested on StackOverflow[7]. Better implementation might be necessary. An alternative function is commented in the `Accuracy.cpp` file.

License
----

Refer to LICENSE

# References
[1] https://lear.inrialpes.fr/people/triggs/pubs/Dalal-cvpr05.pdf
[2] http://www.magicandlove.com/blog/2011/08/26/people-detection-in-opencv-again/
[3] https://github.com/opencv/opencv/blob/master/samples/cpp/peopledetect.cpp
[4] http://answers.opencv.org/question/67091/how-to-find-if-2-rectangles-are-overlapping-each-other/
[5] https://docs.opencv.org/3.1.0/d2/d44/classcv_1_1Rect__.html#a66b63fc11cc3872ff2dad2603278e10e
[6] http://answers.opencv.org/question/189381/how-to-find-out-if-rect-is-inside-another-rect/
[7] https://stackoverflow.com/a/55188799/7347566
