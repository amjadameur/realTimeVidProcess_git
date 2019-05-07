#include "cubicdownsample.h"


void CubicDownSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    FastImage *tmpOut = decreaseImSize(bufferIn);
    int rVal, gVal, bVal;

    for(int y=0; y<tmpOut->height(); y++){
        for(int x=0; x<tmpOut->width(); x++){

            int rSquared = 0, gSquared = 0, bSquared = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j<2; j++) {
                    rSquared  = imInR(2*y+i, 2*x+j)*imInR(2*y+i, 2*x+j);
                    gSquared  = imInG(2*y+i, 2*x+j)*imInG(2*y+i, 2*x+j);
                    bSquared  = imInB(2*y+i, 2*x+j)*imInB(2*y+i, 2*x+j);
                }
            }

            rVal = (int) sqrt(rSquared/4);
            gVal = (int) sqrt(gSquared/4);
            bVal = (int) sqrt(bSquared/4);

            tmpOutR(y, x, rVal);
            tmpOutG(y, x, gVal);
            tmpOutB(y, x, bVal);
        }
    }
    bufferOut->FastImagePointer(tmpOut);
}
