# HOG People Detector

The program uses a HOG people detector trained on s SVM classifier to draw a rectangle that aims to identify the people in the video frame by frame.
The video is passed as input to the program and the algorithm can be run only for one instance; if you need to perform the same operation on other video, please modify the full path accordingly.

As the program starts, the user is asked to choosed between to main methods:
  - DEFAULT
  - DAIMLER

The first uses the default window size, as explained in the original paper (Dalal, Triggs[1]), while the daimler mode uses a SVM trained on humand, over a (48,96) window.
The mode is selected by simply pressing "0" (default) or "1" (daimler).

# If you only want to run the program

# if you want to edit the program
Depending on the IDE you are using, different setup procedures may be required.
The first thing you need is a compiled version of OpenCV (I am using 3.4.3). 
Header libraries are found in /usr/local/include.
Library files are found in /usr/local/lib.

# How to
The .xcodeproj is only needed to open the project with xcode as default IDE, but you are free to use whatever, since the execution is done via terminal (keep on reading).

To build the program, move into the main (highest) project HOG directory and run the following command:

g++ -I /usr/local/include -L /usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_videoio -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_imgcodecs HOG/*.cpp -o build/<platform>/target

Some existing code has been used to write this program[2][3]

License
----

None

# References
[1] https://lear.inrialpes.fr/people/triggs/pubs/Dalal-cvpr05.pdf
[2] http://www.magicandlove.com/blog/2011/08/26/people-detection-in-opencv-again/
[3] https://github.com/opencv/opencv/blob/master/samples/cpp/peopledetect.cpp
[4] http://answers.opencv.org/question/67091/how-to-find-if-2-rectangles-are-overlapping-each-other/
[5] https://docs.opencv.org/3.1.0/d2/d44/classcv_1_1Rect__.html#a66b63fc11cc3872ff2dad2603278e10e
[6] http://answers.opencv.org/question/189381/how-to-find-out-if-rect-is-inside-another-rect/
