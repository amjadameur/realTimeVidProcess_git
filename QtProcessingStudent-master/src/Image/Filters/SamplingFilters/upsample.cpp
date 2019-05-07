#include "upsample.h"


void UpSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    FastImage *tmpOut = increaseImSize(bufferIn);
    int rVal, gVal, bVal;
    for(int y=0; y<bufferIn->height()-1; y++){
        for(int x=0; x<bufferIn->width()-1; x++){
            rVal = imInR(y, x);
            gVal = imInG(y, x);
            bVal = imInB(y, x);

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
