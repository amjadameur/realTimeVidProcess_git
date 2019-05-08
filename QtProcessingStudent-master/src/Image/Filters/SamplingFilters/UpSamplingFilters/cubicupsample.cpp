#include "cubicupsample.h"

void CubicUpSample::rgbCompute(FastImage *bufferIn, int x, int y) {
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
}



