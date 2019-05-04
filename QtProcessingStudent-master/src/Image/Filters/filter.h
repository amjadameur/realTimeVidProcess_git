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
        LinearDownSample         LinearDwSampleFilter;
        CubicDownSample          CubicDwSampleFilter;
        UpSample                 upSampleFilter;
        LinearUpSample           linearUpSampleFilter;
        CubicUpSample            CubicUpSampleFilter;

        Blur                     blurFilter;
        AutoAdapt                autoAdaptFilter;

        DoubleCubicDownSample    DoubleCubicDwSampleFilter;
        BlurLinearUpSample       blurLinearUpSampleFilter;



};












#endif // FILTER

