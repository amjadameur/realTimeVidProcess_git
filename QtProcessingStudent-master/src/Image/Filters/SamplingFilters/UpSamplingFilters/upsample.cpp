#include "upsample.h"

void UpSample::rgbCompute(FastImage *bufferIn, int y, int x) {
    rVal = imInR(y, x);
    gVal = imInG(y, x);
    bVal = imInB(y, x);
}

