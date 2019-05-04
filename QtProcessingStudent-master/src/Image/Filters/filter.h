#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "../FImage.h"

using namespace std;

#ifndef FILTER
#define FILTER

#define imInR(y, x) ((float)bufferIn->Red(y, x))
#define imInG(y, x) ((float)bufferIn->Green(y, x))
#define imInB(y, x) ((float)bufferIn->Blue(y, x))

#define imOutR(y, x, v) bufferOut->Red(y, x, v)
#define imOutG(y, x, v) bufferOut->Green(y, x, v)
#define imOutB(y, x, v) bufferOut->Blue(y, x, v)

/*
class Filter {

public :

    void adjustImDimensions(FastImage* bufferIn, FastImage* bufferOut);
    void bufferOutToBufferIn(FastImage* bufferIn, FastImage* bufferOut);
};
*/











#endif // FILTER

