#include "blur.h"

Blur::Blur() {
    filterName = "Blur";
    cout << filterName << endl;
    prevIm1 = NULL;
    prevIm2 = NULL;
}

Blur::~Blur() {
    delete prevIm1;
    delete prevIm2;
}

void Blur::refreshPrevIm(FastImage *bufferIn) {
    if(prevIm2 == NULL) {
        prevIm2 = new FastImage(bufferIn);
    }
    else if(prevIm1 == NULL) {
        prevIm1 = new FastImage(bufferIn);
    } else {
        prevIm2->FastImageCpy(prevIm1);
        prevIm1->FastImageCpy(bufferIn);
    }
}

bool Blur::differentImSizes(FastImage *bufferIn) {
    if (!((bufferIn->width() == prevIm1->width()) && (bufferIn->height() == prevIm1->height()))) return true;

    return false;
}

void Blur::filter(FastImage *bufferIn, FastImage *bufferOut) {
    if(prevIm2 == NULL || prevIm2 == NULL || differentImSizes(bufferIn)) {
        bufferOut->FastImageCpy(bufferIn);
    } else {
        for(int y=0; y<bufferIn->height(); y++){
            for(int x=0; x<bufferIn->width(); x++){
                    rOut = (int) 0.5*bufferIn->Red(y, x)   + 0.3*prevIm1->Red(y, x)   + 0.2*prevIm2->Red(y, x);
                    gOut = (int) 0.5*bufferIn->Green(y, x) + 0.3*prevIm1->Green(y, x) + 0.2*prevIm2->Green(y, x);
                    bOut = (int) 0.5*bufferIn->Blue(y, x)  + 0.3*prevIm1->Blue(y, x)  + 0.2*prevIm2->Blue(y, x);

                imOutR(y, x, rOut);
                imOutG(y, x, gOut);
                imOutB(y, x, bOut);
            }
        }
    }
}


