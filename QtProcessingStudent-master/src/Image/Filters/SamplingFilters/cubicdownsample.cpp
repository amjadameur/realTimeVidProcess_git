#include "cubicdownsample.h"


void CubicDownSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    FastImage *tmpOut = decreaseImSize(bufferIn);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferOut->height(); y++){
        for(int x=0; x<bufferOut->width(); x++){
            rVal = imInR(2*y, 2*x);
            gVal = imInG(2*y, 2*x);
            bVal = imInB(2*y, 2*x);

            tmpOutR(y, x, rVal);
            tmpOutG(y, x, gVal);
            tmpOutB(y, x, bVal);
        }
    }
    delete bufferOut;
    bufferOut = tmpOut;
}
