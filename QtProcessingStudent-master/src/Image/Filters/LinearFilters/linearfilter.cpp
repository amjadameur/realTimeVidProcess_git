#include "linearfilter.h"



void LinearFilter::setCoeffs(double *coeffs) {
    for (int i = 0; i<9; i++) {
        this->coeffs[i] = coeffs[i];
    }
}


LinearFilter::LinearFilter()  {
    coeffs = new double[9];
}


LinearFilter::~LinearFilter() {
    delete coeffs;
}

void LinearFilter::filter(FastImage* bufferIn, FastImage* bufferOut) {
    unsigned char rIn, gIn, bIn;
    unsigned char *ptrIn  = (unsigned char*) bufferIn->image;
    unsigned int  *ptrOut = (unsigned int*) bufferOut->image;

    unsigned int size = bufferIn->height()*bufferIn->width();

    while(size--) {
        ptrIn++ ; // bypass alpha component
        rIn = *ptrIn++;
        gIn = *ptrIn++;
        bIn = *ptrIn++;

        rVal = coeffs[0]*rIn + coeffs[1]*gIn + coeffs[2]*bIn;
        gVal = coeffs[3]*rIn + coeffs[4]*gIn + coeffs[5]*bIn;
        bVal = coeffs[6]*rIn + coeffs[7]*gIn + coeffs[8]*bIn;

        *ptrOut++ = (0xFF << 24) | (rVal << 16) | (gVal << 8) | (bVal);
    }
}


































