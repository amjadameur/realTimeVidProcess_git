#include "complex1.h"

void C1::filter(FastImage* bufferIn, FastImage* bufferOut) {
    cubicDownSampleFilter.filter(bufferIn, bufferOut);
    tmpIn = bufferOut;
    cubicDownSampleFilter.filter(tmpIn, bufferOut);
    tmpIn = NULL;
}
