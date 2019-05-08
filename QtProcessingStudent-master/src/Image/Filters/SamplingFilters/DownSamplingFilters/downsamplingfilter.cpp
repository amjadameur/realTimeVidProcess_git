#include "downsamplingfilter.h"

FastImage *DownSamplingFilter::decreaseImSize(FastImage* bufferIn) {
    // Dicrease Image Size
    int height = (bufferIn->height()/2);
    int width  = (bufferIn->width() /2);
    return new FastImage(height, width);
}

