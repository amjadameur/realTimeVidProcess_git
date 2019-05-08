#include "upsamplingfilter.h"

FastImage *UpSamplingFilter::increaseImSize(FastImage *bufferIn) {
    // Increase Image Size
    int height = 2*bufferIn->height();
    int width  = 2*bufferIn->width() ;
    return new FastImage(height, width);
}

