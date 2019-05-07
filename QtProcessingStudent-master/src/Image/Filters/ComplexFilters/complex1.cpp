#include "complex1.h"

void Complex1::filter(FastImage* bufferIn, FastImage* bufferOut) {
    cubicDownSampleFilter.filter(bufferIn, bufferOut);
    bufferIn->FastImageCpy(bufferOut);
    cubicDownSampleFilter.filter(bufferIn, bufferOut);
}
