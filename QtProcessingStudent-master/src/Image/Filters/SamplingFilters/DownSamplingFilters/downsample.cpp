#include "downsample.h"

void DownSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    FastImage *tmpOut = decreaseImSize(bufferIn);
    int rVal, gVal, bVal;
    for(int y=0; y<tmpOut->height(); y++){
        for(int x=0; x<tmpOut->width(); x++){
            rVal = imInR(2*y, 2*x);
            gVal = imInG(2*y, 2*x);
            bVal = imInB(2*y, 2*x);

            tmpOutR(y, x, rVal);
            tmpOutG(y, x, gVal);
            tmpOutB(y, x, bVal);
        }
    }
    bufferOut->FastImagePointer(tmpOut);
}

