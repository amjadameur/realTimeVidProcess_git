#include "upsample.h"

void UpSample::rgbCompute(FastImage *bufferIn, int x, int y) {
    rVal = imInR(y, x);
    gVal = imInG(y, x);
    bVal = imInB(y, x);
}

