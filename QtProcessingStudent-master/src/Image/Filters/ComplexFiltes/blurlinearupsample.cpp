#include "blurlinearupsample.h"

BlurLinearUpSample::BlurLinearUpSample() {
    //tmpIn = new FastImage(2, 2);
}

BlurLinearUpSample::~BlurLinearUpSample() {
   // delete tmpIn;
}


void BlurLinearUpSample::filter(FastImage* bufferIn, FastImage* bufferOut) {
    tmpIn = bufferIn;

    redChannelFilter.filter(tmpIn, bufferOut);

    tmpIn = bufferOut;

    reliableGreyFilter.filter(tmpIn, bufferOut);
}

