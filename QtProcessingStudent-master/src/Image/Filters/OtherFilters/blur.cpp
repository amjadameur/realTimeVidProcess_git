#include "blur.h"

Blur::Blur() {
    prevIm1 = NULL;
    prevIm2 = NULL;
}

Blur::~Blur() {
    delete prevIm1;
    delete prevIm2;
}

void Blur::filter(FastImage *bufferIn, FastImage *bufferOut) {
    if(prevIm2 == NULL) {
        prevIm2 = new FastImage(bufferIn);
        bufferOut->FastImageCpy(bufferIn);

    }
    else if(prevIm1 == NULL) {
        prevIm1 = new FastImage(bufferIn);
        bufferOut->FastImageCpy(bufferIn);

    } else {
        int rVal, gVal, bVal;
        for(int y=0; y<bufferIn->height(); y++){
            for(int x=0; x<bufferIn->width(); x++){
                    rVal = (int) 0.5*bufferIn->Red(y, x)   + 0.3*prevIm1->Red(y, x)   + 0.2*prevIm2->Red(y, x);
                    gVal = (int) 0.5*bufferIn->Green(y, x) + 0.3*prevIm1->Green(y, x) + 0.2*prevIm2->Green(y, x);
                    bVal = (int) 0.5*bufferIn->Blue(y, x)  + 0.3*prevIm1->Blue(y, x)  + 0.2*prevIm2->Blue(y, x);

                imOutR(y, x, rVal);
                imOutG(y, x, gVal);
                imOutB(y, x, bVal);
            }
        }
        prevIm2->FastImageCpy(prevIm1);
        prevIm1->FastImageCpy(bufferIn);
    }
}


