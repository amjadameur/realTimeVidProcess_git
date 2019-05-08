#include "complex1.h"

C1::C1() {
    cubicDownSampleFilter = new CubicDownSample();
}

C1::~C1() {
    delete cubicDownSampleFilter;
}

void C1::filter(FastImage* bufferIn, FastImage* bufferOut) {
    cubicDownSampleFilter->filter(bufferIn, bufferOut);
    tmpIn = bufferOut;
    cubicDownSampleFilter->filter(tmpIn, bufferOut);
    tmpIn = NULL;
}
