#include "complex3.h"

Complex3::Complex3(Blur *blurFilter) {
    this->blurFilter = blurFilter;
}


void Complex3::filter(FastImage* bufferIn, FastImage* bufferOut) {

    reliableGreyFilter.filter(bufferIn, bufferOut);

    tmpIn = bufferOut;


}

