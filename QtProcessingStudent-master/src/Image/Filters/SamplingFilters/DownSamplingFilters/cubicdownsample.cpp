#include "cubicdownsample.h"

void CubicDownSample::rgbCompute(FastImage *bufferIn, int x, int y) {
    rVal = 0;
    gVal = 0;
    bVal = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j<2; j++) {
            rVal  += imInR(2*y+i, 2*x+j)*imInR(2*y+i, 2*x+j);
            gVal  += imInG(2*y+i, 2*x+j)*imInG(2*y+i, 2*x+j);
            bVal  += imInB(2*y+i, 2*x+j)*imInB(2*y+i, 2*x+j);
        }
    }

    rVal = (int) sqrt(rVal/4);
    gVal = (int) sqrt(gVal/4);
    bVal = (int) sqrt(bVal/4);
}
