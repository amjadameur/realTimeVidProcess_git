#include "cubicupsample.h"

void CubicUpSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    FastImage *tmpOut = increaseImSize(bufferIn);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferIn->height()-1; y++){
        for(int x=0; x<bufferIn->width()-1; x++){
            rVal = (imInR(y, x) + imInR(y, x+1) + imInR(y+1, x) + imInR(y+1, x+1))/4;
            gVal = (imInG(y, x) + imInG(y, x+1) + imInG(y+1, x) + imInG(y+1, x+1))/4;
            bVal = (imInB(y, x) + imInB(y, x+1) + imInB(y+1, x) + imInB(y+1, x+1))/4;

            tmpOutR(2*y    , 2*x    , rVal);
            tmpOutR(2*y    , 2*(x+1), rVal);
            tmpOutR(2*(y+1), 2*x    , rVal);
            tmpOutR(2*(y+1), 2*(x+1), rVal);

            tmpOutG(2*y    , 2*x    , gVal);
            tmpOutG(2*y    , 2*(x+1), gVal);
            tmpOutG(2*(y+1), 2*x    , gVal);
            tmpOutG(2*(y+1), 2*(x+1), gVal);

            tmpOutB(2*y    , 2*x    , bVal);
            tmpOutB(2*y    , 2*(x+1), bVal);
            tmpOutB(2*(y+1), 2*x    , bVal);
            tmpOutB(2*(y+1), 2*(x+1), bVal);
        }
    }
    bufferOut->FastImagePointer(tmpOut);
}

