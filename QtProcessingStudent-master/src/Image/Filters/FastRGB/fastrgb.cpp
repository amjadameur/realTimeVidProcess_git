#include "fastrgb.h"

void FastRGB::filter(FastImage *bufferIn, FastImage *bufferOut) {
    unsigned int *ptrIn  = (unsigned int*) bufferIn->image;
    unsigned int *ptrOut = (unsigned int*) bufferOut->image;

    unsigned int size = bufferIn->height()*bufferIn->width();

    while(size--) {
        *ptrOut++ = *ptrIn++ & rgbMask;
    }
}
