#include "downsample.h"

DownSample::DownSample() {
    filterName = "Down Sample";
}

void DownSample::rgbCompute(FastImage *bufferIn, int y, int x) {
    rVal = imInR(2*y, 2*x);
    gVal = imInG(2*y, 2*x);
    bVal = imInB(2*y, 2*x);
}


