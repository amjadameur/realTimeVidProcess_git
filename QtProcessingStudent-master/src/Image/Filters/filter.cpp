#include "filter.h"

Filter::Filter() {
    tmp1 = new FastImage(2, 2);
    tmp2 = new FastImage(2, 2);
}

void Filter::filter(int filterIdx, FastImage* previousBuffer2, FastImage* previousBuffer1, FastImage* bufferIn, FastImage* bufferOut) {

    switch(filterIdx) {
        case REDFILTER :
            redFilter.filter(bufferIn, bufferOut);
            break;

        case GREENFILTER :
            greenFilter.filter(bufferIn, bufferOut);
            break;

        case BLUEFILTER :
            blueFilter.filter(bufferIn, bufferOut);
            break;

        case GREYFILTER :
            greyFilter.filter(bufferIn, bufferOut);
            break;

        case RELIABLEGREYFILTER :
            reliableGreyFilter.filter(bufferIn, bufferOut);
            break;

        case DWSAMPLEFILTER :
            dwSampleFilter.filter(bufferIn, bufferOut);
            break;

        case LINEARDWSAMPLEFILTER :
            linearDwSampleFilter.filter(bufferIn, bufferOut);
            break;

        case CUBICDWSAMPLEFILTER :
            cubicDwSampleFilter.filter(bufferIn, bufferOut);
            break;

        case UPSAMPLEFILTER :
            upSampleFilter.filter(bufferIn, bufferOut);
            break;

        case LINEARUPSAMPLEFILTER :
            linearUpSampleFilter.filter(bufferIn, bufferOut);
            break;

        case CUBICUPSAMPLEFILTER :
            cubicUpSampleFilter.filter(bufferIn, bufferOut);
            break;



        case AUTOADAPTFILTER :
            autoAdaptFilter.filter(bufferIn, bufferOut);
            break;

        case INVERSEFILTER :
            inverseFilter.filter(bufferIn, bufferOut);
            break;

        case DOUBLECUBICDWSAMPLEFILTER :
            doubleCubicDwSampleFilter.filter(bufferIn, bufferOut);
            break;
/*
        case BLURLINEARUPSAMPLEFILTER :
            blurLinearUpSampleFilter.filter(previousBuffer2, previousBuffer1, bufferIn, bufferOut);
            break;*/
    }
}

void Filter::applySelectedFilters(int *fifo, FastImage* previousBuffer2, FastImage* previousBuffer1,
                                  FastImage* bufferIn, FastImage* bufferOut) {
    tmp1->FastImageCpy(bufferIn);
    tmp2->FastImageCpy(bufferIn);

    for (int i = 0; i<NB_FILTERS; i++) {
        if (fifo[i] != 0) {
            filter(fifo[i], previousBuffer2, previousBuffer1, tmp1, tmp2);
            tmp1->FastImageCpy(tmp2);
        }
    }
    bufferOut->FastImageCpy(tmp2);
}
