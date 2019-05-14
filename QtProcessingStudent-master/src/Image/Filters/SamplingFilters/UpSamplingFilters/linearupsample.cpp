#include "linearupsample.h"

LinearUpSample::LinearUpSample() {
    filterName = "Linear Up Sample";
}

void LinearUpSample::rgbCompute(FastImage *bufferIn, int y, int x) {
    if (XYOutOfRange(bufferIn, y+1, x+1)) {
        rVal = imInR(y, x);
        gVal = imInG(y, x);
        bVal = imInB(y, x);

    } else {
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
}




