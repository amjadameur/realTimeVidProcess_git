#include "linearfilter.h"

void LinearFilter::rgbCompute() {
    // méthode traduisant le cas général d'un filtrage linéaire, elle serait redéfinie par les canaux RGB
    ptrIn++;        // bypass alpha component
    rIn = *ptrIn++;
    gIn = *ptrIn++;
    bIn = *ptrIn++;

    unsigned char weightedRGB = coeff1*rIn + coeff2*gIn + coeff3*bIn;

    *ptrOut++ = (0xFF << 24) | (weightedRGB << 16) | (weightedRGB << 8) | (weightedRGB);
}

void LinearFilter::filter(FastImage* bufferIn, FastImage* bufferOut) {
    ptrIn  = (unsigned char*) bufferIn->image;
    ptrOut = (unsigned int*) bufferOut->image;

    unsigned int size = bufferIn->height()*bufferIn->width();

    while(size--) {
        rgbCompute();
    }
}


































