#include "cubicupsample.h"

void CubicUpSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    FastImage *tmpOut = increaseImSize(bufferIn);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferIn->height()-1; y++){
        for(int x=0; x<bufferIn->width()-1; x++){
            rVal = 0;
            gVal = 0;
            bVal = 0;

            for(int i = 0; i<2; i++) {
                for(int j = 0; j<2; j++) {
                    rVal += imInR(y+i, x+i)*imInR(y+i, x+i);
                    gVal += imInG(y+i, x+i)*imInG(y+i, x+i);
                    bVal += imInB(y+i, x+i)*imInB(y+i, x+i);
                }
            }

            rVal = sqrt(rVal/4);
            gVal = sqrt(gVal/4);
            bVal = sqrt(bVal/4);

            for(int i = 0; i<2; i++) {
                for(int j = 0; j<2; j++) {
                    tmpOutR(2*y+i, 2*x+j, rVal);
                    tmpOutG(2*y+i, 2*x+j, gVal);
                    tmpOutB(2*y+i, 2*x+j, bVal);
                }
            }
        }
    }
    bufferOut->FastImagePointer(tmpOut);
}

