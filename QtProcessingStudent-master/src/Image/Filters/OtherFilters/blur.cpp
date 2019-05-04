#include "blur.h"

void Blur::filter(FastImage *previousBuffer2, FastImage *previousBuffer1, FastImage *bufferIn, FastImage *bufferOut) {
    int rVal, gVal, bVal;
    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
                rVal = (int) 0.5*bufferIn->Red(y, x) + 0.3*previousBuffer1->Red(y, x) + 0.2*previousBuffer2->Red(y, x);
                gVal = (int) 0.5*bufferIn->Green(y, x) + 0.3*previousBuffer1->Green(y, x) + 0.2*previousBuffer2->Green(y, x);
                bVal = (int) 0.5*bufferIn->Blue(y, x) + 0.3*previousBuffer1->Blue(y, x) + 0.2*previousBuffer2->Blue(y, x);

            imOutR(y, x, rVal);
            imOutG(y, x, gVal);
            imOutB(y, x, bVal);
        }
    }
}


