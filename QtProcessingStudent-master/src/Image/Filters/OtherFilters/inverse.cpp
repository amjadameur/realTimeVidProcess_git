#include "inverse.h"

void Inverse::filter(FastImage *bufferIn, FastImage *bufferOut) {
    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            rVal = 255 - imInR(y,x);
            gVal = 255 - imInG(y,x);
            bVal = 255 - imInB(y,x);

            imOutR(y, x, rVal);
            imOutG(y, x, gVal);
            imOutB(y, x, bVal);
        }
    }
}
