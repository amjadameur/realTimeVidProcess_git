#include "autoadapt.h"

void AutoAdapt::filter(FastImage *bufferIn, FastImage *bufferOut) {
    int rVal, gVal, bVal;
    int minR, maxR, minG, maxG, minB, maxB;
    minR = imInR(0, 0); maxR = imInR(0, 0);
    minG = imInG(0, 0); maxG = imInG(0, 0);
    minB = imInB(0, 0); maxB = imInB(0, 0);

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            if (imInR(y, x) < minR) minR = imInR(y, x);
            if (imInR(y, x) > maxR) maxR = imInR(y, x);

            if (imInG(y, x) < minG) minG = imInG(y, x);
            if (imInG(y, x) > maxG) maxG = imInG(y, x);

            if (imInB(y, x) < minB) minB = imInB(y, x);
            if (imInB(y, x) > maxB) maxB = imInB(y, x);
        }
    }

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            rVal = (int) (255*(imInR(y, x)-minR))/(maxR-minR);
            gVal = (int) (255*(imInG(y, x)-minG))/(maxG-minG);
            bVal = (int) (255*(imInB(y, x)-minB))/(maxB-minB);

            imOutR(y, x, rVal);
            imOutG(y, x, gVal);
            imOutB(y, x, bVal);
        }
    }
}
