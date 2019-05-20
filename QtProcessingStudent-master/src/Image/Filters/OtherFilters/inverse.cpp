#include "inverse.h"

Inverse::Inverse() {
    filterName = "Inverse";
}

void Inverse::filter(FastImage *bufferIn, FastImage *bufferOut) {    
    unsigned char *ptrIn  = (unsigned char*) bufferIn->image;
    unsigned int  *ptrOut = (unsigned int*) bufferOut->image;

    unsigned int size = bufferIn->height()*bufferIn->width();

    while(size--) {
        ptrIn++ ; // bypass alpha component
        rIn = *ptrIn++;
        gIn = *ptrIn++;
        bIn = *ptrIn++;

        rOut = 255 - rIn;
        gOut = 255 - gIn;
        bOut = 255 - bIn;

        *ptrOut++ = (0xFF << 24) | (rOut << 16) | (gOut << 8) | (bOut);
    }
}
