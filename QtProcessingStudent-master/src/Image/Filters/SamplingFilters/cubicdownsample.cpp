#include "cubicdownsample.h"


void CubicDownSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    reduceImSize(bufferIn, bufferOut);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferOut->height(); y++){
        for(int x=0; x<bufferOut->width(); x++){
            rVal = imInR(2*y, 2*x);
            gVal = imInG(2*y, 2*x);
            bVal = imInB(2*y, 2*x);

            imOutR(y, x, rVal);
            imOutG(y, x, gVal);
            imOutB(y, x, bVal);
        }
    }
}
