#include "downsample.h"

void DownSample::rgbCompute(FastImage *bufferIn, int x, int y) {
    rVal = imInR(2*y, 2*x);
    gVal = imInG(2*y, 2*x);
    bVal = imInB(2*y, 2*x);
}


