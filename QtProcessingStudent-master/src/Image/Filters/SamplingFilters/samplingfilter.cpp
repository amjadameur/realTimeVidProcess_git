#include "samplingfilter.h"

#define RESIZE_FACTOR 2


FastImage *SamplingFilter::decreaseImSize(FastImage* bufferIn) {
    // Dicrease Image Size
    int height = (bufferIn->height()/2) +1;
    int width  = (bufferIn->width() /2) +1;
    return new FastImage(height, width);
}

FastImage *SamplingFilter::increaseImSize(FastImage *bufferIn) {
    // Increase Image Size
    int height = 2*bufferIn->height();
    int width  = 2*bufferIn->width() ;
    return new FastImage(height, width);
}




