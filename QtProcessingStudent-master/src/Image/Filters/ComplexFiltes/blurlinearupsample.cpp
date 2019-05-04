#include "blurlinearupsample.h"

BlurLinearUpSample::BlurLinearUpSample() {
    tmp1 = new FastImage(2, 2);
    tmp2 = new FastImage(2, 2);
}

BlurLinearUpSample::~BlurLinearUpSample() {
    delete tmp1;
    delete tmp2;
}

void BlurLinearUpSample::refreshTmp() {
    tmp1->FastImageCpy(tmp2);
}

void BlurLinearUpSample::filter(FastImage* previousBuffer2, FastImage* previousBuffer1,
                                FastImage* bufferIn, FastImage* bufferOut) {

    tmp1->FastImageCpy(bufferIn);
    tmp2->FastImageCpy(bufferIn);

    blurFilter.filter(previousBuffer2, previousBuffer1, tmp1, tmp2);
    refreshTmp();

    reliableGreyFilter.filter(tmp1, tmp2);
    refreshTmp();

    linearUpSampleFilter.filter(tmp1, tmp2);

    bufferOut->FastImageCpy(tmp2);
}

