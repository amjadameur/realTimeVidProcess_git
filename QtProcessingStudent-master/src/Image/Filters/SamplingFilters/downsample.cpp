#include "downsample.h"

void DownSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    reduceImSize(bufferIn, bufferOut);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferOut->height(); y++){
        for(int x=0; x<bufferOut->width(); x++){
            rVal = (int) sqrt((pow(imInR(2*y, 2*x), 2) + pow(imInR(2*y, 2*(x+1)), 2) + pow(imInR(2*(y+1), 2*x), 2) + pow(imInR(2*(y+1), 2*(x+1)), 2))/4);
            gVal = (int) sqrt((pow(imInG(2*y, 2*x), 2) + pow(imInG(2*y, 2*(x+1)), 2) + pow(imInG(2*(y+1), 2*x), 2) + pow(imInG(2*(y+1), 2*(x+1)), 2))/4);
            bVal = (int) sqrt((pow(imInB(2*y, 2*x), 2) + pow(imInB(2*y, 2*(x+1)), 2) + pow(imInB(2*(y+1), 2*x), 2) + pow(imInB(2*(y+1), 2*(x+1)), 2))/4);

            imOutR(y, x, rVal);
            imOutG(y, x, gVal);
            imOutB(y, x, bVal);
        }
    }
}

