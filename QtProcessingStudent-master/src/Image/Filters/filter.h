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
#include "OtherFilters/inverse.h"

// Complex filters
#include "ComplexFiltes/doublecubicdownsample.h"
#include "ComplexFiltes/blurlinearupsample.h"

#define REDFILTER                  1
#define GREENFILTER                2
#define BLUEFILTER                 3
#define GREYFILTER                 4
#define RELIABLEGREYFILTER         5
#define DWSAMPLEFILTER             6
#define LINEARDWSAMPLEFILTER       7
#define CUBICDWSAMPLEFILTER        8
#define UPSAMPLEFILTER             9
#define LINEARUPSAMPLEFILTER       10
#define CUBICUPSAMPLEFILTER        11
#define BLURFILTER                 12
#define AUTOADAPTFILTER            13
#define INVERSEFILTER              14
#define DOUBLECUBICDWSAMPLEFILTER  15
#define BLURLINEARUPSAMPLEFILTER   16

#define NB_FILTERS 16

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
        Inverse                  inverseFilter;

        DoubleCubicDownSample    doubleCubicDwSampleFilter;
        BlurLinearUpSample       blurLinearUpSampleFilter;

public :
        Filter();
        void filter(int filterIdx, FastImage* previousBuffer2, FastImage* previousBuffer1, FastImage* bufferIn, FastImage* bufferOut);
        void applySelectedFilters(int *fifo, FastImage* previousBuffer2, FastImage* previousBuffer1, FastImage* bufferIn, FastImage* bufferOut);
};

#endif // FILTER

