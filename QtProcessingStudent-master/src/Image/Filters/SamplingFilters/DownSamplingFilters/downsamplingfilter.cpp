#include "downsamplingfilter.h"

FastImage *DownSamplingFilter::fastImageResize(FastImage* bufferIn) {
    // Dicrease Image Size
    int height = ceil(bufferIn->height()/2);
    int width  = ceil(bufferIn->width() /2);
    return new FastImage(height, width);
}

void DownSamplingFilter::rgbAssign(FastImage* bufferOut, int y, int x) {
    imOutR(y, x, rVal);
    imOutG(y, x, gVal);
    imOutB(y, x, bVal);
}



