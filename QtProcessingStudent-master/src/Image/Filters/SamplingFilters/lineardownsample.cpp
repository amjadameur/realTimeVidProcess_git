#include "lineardownsample.h"

void LinearDownSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    reduceImSize(bufferIn, bufferOut);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferOut->height(); y++){
        for(int x=0; x<bufferOut->width(); x++){
            rVal = (imInR(2*y, 2*x) + imInR(2*y, 2*(x+1)) + imInR(2*(y+1), 2*x) + imInR(2*(y+1), 2*(x+1)))/4;
            gVal = (imInG(2*y, 2*x) + imInG(2*y, 2*(x+1)) + imInG(2*(y+1), 2*x) + imInG(2*(y+1), 2*(x+1)))/4;
            bVal = (imInB(2*y, 2*x) + imInB(2*y, 2*(x+1)) + imInB(2*(y+1), 2*x) + imInB(2*(y+1), 2*(x+1)))/4;

            imOutR(y, x, rVal);
            imOutG(y, x, gVal);
            imOutB(y, x, bVal);
        }
    }
}

