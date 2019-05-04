#include "upsample.h"


void UpSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    increaseImSize(bufferIn, bufferOut);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferIn->height()-1; y++){
        for(int x=0; x<bufferIn->width()-1; x++){
            rVal = imInR(y, x);
            gVal = imInG(y, x);
            bVal = imInB(y, x);

            imOutR(2*y    , 2*x    , rVal);
            imOutR(2*y    , 2*(x+1), rVal);
            imOutR(2*(y+1), 2*x    , rVal);
            imOutR(2*(y+1), 2*(x+1), rVal);

            imOutG(2*y    , 2*x    , gVal);
            imOutG(2*y    , 2*(x+1), gVal);
            imOutG(2*(y+1), 2*x    , gVal);
            imOutG(2*(y+1), 2*(x+1), gVal);

            imOutB(2*y    , 2*x    , bVal);
            imOutB(2*y    , 2*(x+1), bVal);
            imOutB(2*(y+1), 2*x    , bVal);
            imOutB(2*(y+1), 2*(x+1), bVal);
        }
    }
}
