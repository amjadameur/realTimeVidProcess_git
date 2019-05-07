#include "complex1.h"

void DoubleCubicDownSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    cubicDownSampleFilter.filter(bufferIn, bufferOut);
    bufferIn->FastImageCpy(bufferOut);
    cubicDownSampleFilter.filter(bufferIn, bufferOut);
}
