#include "upsamplingfilter.h"

FastImage *UpSamplingFilter::increaseImSize(FastImage *bufferIn) {
    // Increase Image Size
    int height = 2*bufferIn->height();
    int width  = 2*bufferIn->width() ;
    return new FastImage(height, width);
}

void UpSamplingFilter::rgbAssign(FastImage *bufferOut, int x, int y) {
    for(int i = 0; i<2; i++) {
        for(int j = 0; j<2; j++) {
            imOutR(2*y+i, 2*x+j, rVal);
            imOutG(2*y+i, 2*x+j, gVal);
            imOutB(2*y+i, 2*x+j, bVal);
        }
    }
}

void UpSamplingFilter::filter(FastImage *bufferIn, FastImage *bufferOut) {
    FastImage *tmpOut = increaseImSize(bufferIn);

    for(int y=0; y<bufferIn->height()-1; y++){
        for(int x=0; x<bufferIn->width()-1; x++){

            rgbCompute(bufferIn, x, y);

            rgbAssign(tmpOut, x, y);

        }
    }

    bufferOut->FastImagePointer(tmpOut);
}
