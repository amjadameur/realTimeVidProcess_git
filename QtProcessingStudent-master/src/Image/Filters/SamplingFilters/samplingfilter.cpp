#include "samplingfilter.h"

#define RESIZE_FACTOR 2


FastImage *SamplingFilter::decreaseImSize(FastImage* bufferIn) {
    // Dicrease Image Size
    int height = ceil((bufferIn->height())/RESIZE_FACTOR);
    int width  = ceil((bufferIn->width())/RESIZE_FACTOR);
    return (new FastImage(width, height));
}

FastImage *SamplingFilter::increaseImSize(FastImage *bufferIn) {
    // Increase Image Size
    int height = bufferIn->height()*RESIZE_FACTOR;
    int width  = bufferIn->width() *RESIZE_FACTOR;
    return (new FastImage(height, width));
}




