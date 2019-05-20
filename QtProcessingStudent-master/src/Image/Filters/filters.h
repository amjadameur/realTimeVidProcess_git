
#ifndef FILTERS_H
#define FILTERS_H

// Linear filters
#include "LinearFilters/redchannel.h"
#include "LinearFilters/greenchannel.h"
#include "LinearFilters/bluechannel.h"
#include "LinearFilters/greychannel.h"
#include "LinearFilters/reliablegreychannel.h"

// Sampling filters
#include "SamplingFilters/DownSamplingFilters/downsample.h"
#include "SamplingFilters/DownSamplingFilters/lineardownsample.h"
#include "SamplingFilters/DownSamplingFilters/cubicdownsample.h"

#include "SamplingFilters/UpSamplingFilters/upsample.h"
#include "SamplingFilters/UpSamplingFilters/linearupsample.h"
#include "SamplingFilters/UpSamplingFilters/cubicupsample.h"

// Other Filters
#include "OtherFilters/blur.h"
#include "OtherFilters/autoadapt.h"
#include "OtherFilters/inverse.h"


// Conv Filters
#include "ConvFilters/Convfilter.h"
#include "ConvFilters/B0.h"
#include "ConvFilters/B1.h"
#include "ConvFilters/B2.h"
#include "ConvFilters/B3.h"
#include "ConvFilters/M0.h"
#include "ConvFilters/M1.h"
#include "ConvFilters/M2.h"
#include "ConvFilters/M3.h"
#include "ConvFilters/M4.h"
#include "ConvFilters/M5.h"
#include "ConvFilters/M6.h"
#include "ConvFilters/M7.h"
#include "ConvFilters/M8.h"
#include "ConvFilters/M9.h"

// Complex filters
#include "ComplexFilters/complex1.h"
#include "ComplexFilters/complex2.h"
#include "ComplexFilters/complex3.h"
#include "ComplexFilters/complex4.h"



class Filters {
public :
    FastImage         *buffOutptr;
    unsigned int       nbFilters;
    vector<Filter*>    filters;
    std::vector<int>   &chosenFilters;
    Filter *blurPtr;

public :
    Filters(std::vector<int> &vect);
    ~Filters();

    //unsigned int nbFilters() {}

    bool allFiltersOff();
    void refreshPrevBuffers(FastImage *bufferIn);

    void filter(FastImage *bufferIn, FastImage *bufferOut);

    // On peut ajouter d'autres méthodes : addFilter, popFilter, insert, swap ..
};


#endif // FILTERS_H
