#include "complex4.h"

C4::C4() {
    filterName = "C4";
    FlouFilter = new B3();
    EdgeDetectionFilter = new M3();
    GreyChannelFilter = new GreyChannel();
}

C4::~C4(){
    delete FlouFilter;
    delete EdgeDetectionFilter;
    delete GreyChannelFilter;
}

void C4::filter(FastImage *bufferIn, FastImage *bufferOut) {
    EdgeDetectionFilter->filter(bufferIn, bufferOut);
    tmpIn = bufferOut;
    GreyChannelFilter->filter(tmpIn, bufferOut);
    tmpIn = bufferOut;
    FlouFilter->filter(tmpIn,bufferOut);
    tmpIn = NULL;
}
