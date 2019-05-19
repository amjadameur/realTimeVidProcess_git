#include "complex2.h"

C2::C2() {
    filterName = "C2";
    CubicDownSampleFilter = new CubicDownSample();
    EdgeDetectionFilter = new M3();
}
C2::~C2(){
    delete CubicDownSampleFilter;
    delete EdgeDetectionFilter;
}

void C2::filter(FastImage *bufferIn, FastImage *bufferOut) {
    EdgeDetectionFilter->filter(bufferIn, bufferOut);
    tmpIn = bufferOut;
    CubicDownSampleFilter->filter(tmpIn, bufferOut);
    tmpIn = NULL;
}
