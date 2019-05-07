#include "complex3.h"

Complex3::Complex3(Blur *blurFilter) {
    this->blurFilter = blurFilter;
    tmpIn = NULL;
}


void Complex3::filter(FastImage* bufferIn, FastImage* bufferOut) {
    blurFilter->filter(bufferIn, bufferOut);
    tmpIn = bufferOut;

    reliableGreyFilter.filter(tmpIn, bufferOut);
    //tmpIn = bufferOut;

  //  linearUpSampleFilter.filter(tmpIn, bufferOut);
   // tmpIn = NULL;
}

