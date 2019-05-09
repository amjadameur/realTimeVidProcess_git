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

#define  RED                   0
#define  GREEN                 1
#define  BLUE                  2
#define  GREY                  3
#define  RELIABLEGREY          4

#define  DWSAMPLE              5
#define  LINEARDWSAMPLE        6
#define  CUBICDWSAMPLE         7
#define  UPSAMPLE              8
#define  LINEARUPSAMPLE        9
#define  CUBICUPSAMPLE        10

#define  BLUR                 11
#define  AUTOADAPT            12
#define  INVERSE              13

#define  CONVB0               14
#define  CONVB1               15
#define  CONVB2               16
#define  CONVB3               17
#define  CONVM0               18
#define  CONVM1               19
#define  CONVM2               20
#define  CONVM3               21
#define  CONVM4               22
#define  CONVM5               23
#define  CONVM6               24
#define  CONVM7               25
#define  CONVM8               26
#define  CONVM9               27

#define  COMPLEX1             28
#define  COMPLEX2             29
#define  COMPLEX3             30
#define  COMPLEX4             31

#define  NB_FILTERS           32

class Filters {
public :
    FastImage         *bufferTmp;
    vector<Filter*>    filters;
    std::vector<int>  &chosenFilters;

    Filters(std::vector<int> &vect);
    ~Filters();

    void refreshPrevBuffers(FastImage *bufferIn);
    void filter(FastImage *bufferIn, FastImage *bufferOut);

    // On peut ajouter d'autres méthodes : addFilter, popFilter, insert, swap ..
};

#endif // FILTERS_H
