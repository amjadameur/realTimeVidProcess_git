#include "complex3.h"

Complex3::Complex3(Blur *_blurFilter) {
    blurFilter = _blurFilter;
    tmpIn = NULL;
}


void Complex3::filter(FastImage* bufferIn, FastImage* bufferOut) {

    blurFilter->filter(bufferIn, bufferOut);
    tmpIn = bufferOut;

    reliableGreyFilter.filter(tmpIn, bufferOut);
    tmpIn = bufferOut;

    UpSampleFilter.filter(tmpIn, bufferOut);
    tmpIn = NULL;
}

