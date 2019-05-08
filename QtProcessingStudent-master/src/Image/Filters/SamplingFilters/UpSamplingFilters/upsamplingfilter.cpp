#include "upsamplingfilter.h"

FastImage *UpSamplingFilter::fastImageResize(FastImage *bufferIn) {
    // Increase Image Size
    int height = 2*bufferIn->height();
    int width  = 2*bufferIn->width() ;
    return new FastImage(height, width);
}

void UpSamplingFilter::rgbAssign(FastImage *bufferOut, int y, int x) {
    for(int i = 0; i<2; i++) {
        for(int j = 0; j<2; j++) {
            imOutR(2*y+i, 2*x+j, rVal);
            imOutG(2*y+i, 2*x+j, gVal);
            imOutB(2*y+i, 2*x+j, bVal);
        }
    }
}


