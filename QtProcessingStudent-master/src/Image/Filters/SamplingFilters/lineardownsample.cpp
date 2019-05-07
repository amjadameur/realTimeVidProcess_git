#include "lineardownsample.h"

void LinearDownSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    FastImage *tmpOut = decreaseImSize(bufferIn);
    int rVal, gVal, bVal;
    for(int y=0; y<tmpOut->height(); y++){
        for(int x=0; x<tmpOut->width(); x++){
            rVal = (imInR(2*y, 2*x) + imInR(2*y, 2*(x+1)) + imInR(2*(y+1), 2*x) + imInR(2*(y+1), 2*(x+1)))/4;
            gVal = (imInG(2*y, 2*x) + imInG(2*y, 2*(x+1)) + imInG(2*(y+1), 2*x) + imInG(2*(y+1), 2*(x+1)))/4;
            bVal = (imInB(2*y, 2*x) + imInB(2*y, 2*(x+1)) + imInB(2*(y+1), 2*x) + imInB(2*(y+1), 2*(x+1)))/4;

            tmpOutR(y, x, rVal);
            tmpOutG(y, x, gVal);
            tmpOutB(y, x, bVal);
        }
    }
    bufferOut->FastImagePointer(tmpOut);
}

