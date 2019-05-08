#include "linearupsample.h"

void LinearUpSample::rgbCompute(FastImage *bufferIn, int x, int y) {
    rVal = 0;
    gVal = 0;
    bVal = 0;

    for(int i = 0; i<2; i++) {
        for(int j = 0; j<2; j++) {
            rVal += imInR(y+i, x+j);
            gVal += imInG(y+i, x+j);
            bVal += imInB(y+i, x+j);
        }
    }

    rVal /= 4;
    gVal /= 4;
    bVal /= 4;
}




