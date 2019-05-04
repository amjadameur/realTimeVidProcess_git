#include "samplingfilter.h"

#define RESIZE_FACTOR 2


void SamplingFilter::reduceImSize(FastImage* bufferIn, FastImage* bufferOut) {
    // Dicrease Image Size
    int new_height = ceil((bufferIn->height())/RESIZE_FACTOR);
    int new_width  = ceil((bufferIn->width())/RESIZE_FACTOR);
    bufferOut->resize(new_height, new_width);
}

void SamplingFilter::increaseImSize(FastImage *bufferIn, FastImage *bufferOut) {
    // Increase Image Size
    int new_height = ((bufferIn->height())*RESIZE_FACTOR);
    int new_width  = ((bufferIn->width() )*RESIZE_FACTOR);
    bufferOut->resize(new_height, new_width);
}




