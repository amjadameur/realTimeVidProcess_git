#include "cubicupsample.h"

void CubicUpSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    increaseImSize(bufferIn, bufferOut);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferIn->height()-1; y++){
        for(int x=0; x<bufferIn->width()-1; x++){
            rVal = (imInR(y, x) + imInR(y, x+1) + imInR(y+1, x) + imInR(y+1, x+1))/4;
            gVal = (imInG(y, x) + imInG(y, x+1) + imInG(y+1, x) + imInG(y+1, x+1))/4;
            bVal = (imInB(y, x) + imInB(y, x+1) + imInB(y+1, x) + imInB(y+1, x+1))/4;

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

