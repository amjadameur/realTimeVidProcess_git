#ifndef FILTER
#define FILTER

// Linear filters
#include "LinearFilters/redchannel.h"
#include "LinearFilters/greenchannel.h"
#include "LinearFilters/bluechannel.h"
#include "LinearFilters/greychannel.h"
#include "LinearFilters/reliablegreychannel.h"

// Sampling filters
#include "SamplingFilters/downsample.h"
#include "SamplingFilters/lineardownsample.h"
#include "SamplingFilters/cubicdownsample.h"
#include "SamplingFilters/upsample.h"
#include "SamplingFilters/linearupsample.h"
#include "SamplingFilters/cubicupsample.h"

// Other Filters
#include "OtherFilters/blur.h"
#include "OtherFilters/autoadapt.h"

// Complex filters
#include "ComplexFiltes/doublecubicdownsample.h"
#include "ComplexFiltes/blurlinearupsample.h"

#define REDFILTER 0
#define GREENFILTER                1
#define BLUEFILTER                 2
#define GREYFILTER                 3
#define RELIABLEGREYFILTER         4
#define DWSAMPLEFILTER             5
#define LINEARDWSAMPLEFILTER       6
#define CUBICDWSAMPLEFILTER        7
#define UPSAMPLEFILTER             8
#define LINEARUPSAMPLEFILTER       9
#define CUBICUPSAMPLEFILTER        10
#define BLURFILTER                 11
#define AUTOADAPTFILTER            12
#define DOUBLECUBICDWSAMPLEFILTER  13
#define BLURLINEARUPSAMPLEFILTER   14

class Filter {
private :
        FastImage* tmp1;
        FastImage* tmp2;

        RedChannel               redFilter;
        GreenChannel             greenFilter;
        BlueChannel              blueFilter;
        GreyChannel              greyFilter;
        ReliableGreyChannel      reliableGreyFilter;

        DownSample               dwSampleFilter;
        LinearDownSample         linearDwSampleFilter;
        CubicDownSample          cubicDwSampleFilter;
        UpSample                 upSampleFilter;
        LinearUpSample           linearUpSampleFilter;
        CubicUpSample            cubicUpSampleFilter;

        Blur                     blurFilter;
        AutoAdapt                autoAdaptFilter;

        DoubleCubicDownSample    doubleCubicDwSampleFilter;
        BlurLinearUpSample       blurLinearUpSampleFilter;

public :
        void filter(int filterIdx, FastImage* previousBuffer2, FastImage* previousBuffer1, FastImage* bufferIn, FastImage* bufferOut);
};












#endif // FILTER

