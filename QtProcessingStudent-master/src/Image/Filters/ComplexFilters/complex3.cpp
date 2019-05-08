#include "complex3.h"

C3::C3(Blur *_blurFilter) {
    blurFilter = _blurFilter;
    tmpIn = NULL;
}


void C3::filter(FastImage* bufferIn, FastImage* bufferOut) {

    blurFilter->filter(bufferIn, bufferOut);
    tmpIn = bufferOut;

    reliableGreyFilter.filter(tmpIn, bufferOut);
    tmpIn = bufferOut;

    linearUpSampleFilter.filter(tmpIn, bufferOut);
    tmpIn = NULL;
}

