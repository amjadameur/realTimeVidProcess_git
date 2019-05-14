#include "upsample.h"

UpSample::UpSample() {
    filterName = "Up Sample";
}

void UpSample::rgbCompute(FastImage *bufferIn, int y, int x) {
    rVal = imInR(y, x);
    gVal = imInG(y, x);
    bVal = imInB(y, x);
}

