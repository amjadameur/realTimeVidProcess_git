#include "samplingfilter.h"

#define UPSAMPLING   2
#define DOWNSAMPLING 1

int min(int a, int b) {
    return (a < b) ? a : b;
}

bool SamplingFilter::XYOutOfRange(FastImage *bufferIn, int y, int x) {
    if ((x > bufferIn->width()) || (y > bufferIn->height())) return true;
    return false;
}

void SamplingFilter::filter(FastImage *bufferIn, FastImage *bufferOut) {
    FastImage *tmpOut = fastImageResize(bufferIn);

    // We choose the min value of width of height to have a reference size, that allows us to generalize
    // this method for both up sampling and down sampling
    int height = min(bufferIn->height(), tmpOut->height());
    int width  = min(bufferIn->width() , tmpOut->width());

    for(int y=0; y< height; y++){
        for(int x=0; x< width;  x++){
            rgbCompute(bufferIn, y, x);
            rgbAssign(tmpOut, y, x);
        }
    }

    bufferOut->FastImagePointer(tmpOut);
}

