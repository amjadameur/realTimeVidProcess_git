#include "filter.h"


void Filter::filter(int filterIdx, FastImage* previousBuffer2, FastImage* previousBuffer1, FastImage* bufferIn, FastImage* bufferOut) {
//redFilter.filter(bufferIn, bufferOut);
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

        case BLURFILTER :
            blurFilter.filter(previousBuffer2, previousBuffer1, bufferIn, bufferOut);
            break;

        case AUTOADAPTFILTER :
            autoAdaptFilter.filter(bufferIn, bufferOut);
            break;

        case DOUBLECUBICDWSAMPLEFILTER :
            doubleCubicDwSampleFilter.filter(bufferIn, bufferOut);
            break;

        case BLURLINEARUPSAMPLEFILTER :
            blurLinearUpSampleFilter.filter(previousBuffer2, previousBuffer1, bufferIn, bufferOut);
            break;
    }

}
