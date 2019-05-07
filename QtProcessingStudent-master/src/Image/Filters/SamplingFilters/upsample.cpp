#include "upsample.h"


void UpSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    FastImage *tmpOut = increaseImSize(bufferIn);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferIn->height()-1; y++){
        for(int x=0; x<bufferIn->width()-1; x++){
            rVal = imInR(y, x);
            gVal = imInG(y, x);
            bVal = imInB(y, x);

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
    delete bufferOut;
    bufferOut = new FastImage(tmpOut);
    delete tmpOut;
}
