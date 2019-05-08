#include "downsamplingfilter.h"

FastImage *DownSamplingFilter::decreaseImSize(FastImage* bufferIn) {
    // Dicrease Image Size
    int height = (bufferIn->height()/2);
    int width  = (bufferIn->width() /2);
    return new FastImage(height, width);
}

void DownSamplingFilter::filter(FastImage *bufferIn, FastImage *bufferOut) {
    FastImage *tmpOut = decreaseImSize(bufferIn);

    for(int y=0; y<tmpOut->height(); y++){
        for(int x=0; x<tmpOut->width(); x++){

            rgbCompute(bufferIn, x, y);

            tmpOutR(y, x, rVal);
            tmpOutG(y, x, gVal);
            tmpOutB(y, x, bVal);
        }
    }
    bufferOut->FastImagePointer(tmpOut);
}

