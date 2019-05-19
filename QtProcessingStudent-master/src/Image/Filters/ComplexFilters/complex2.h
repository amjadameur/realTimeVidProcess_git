#ifndef C2_H
#define C2_H

#include "../filter.h"
#include "../SamplingFilters/DownSamplingFilters/cubicdownsample.h"
#include "../ConvFilters/M3.h"


class C2 : public Filter {
private :
    DownSamplingFilter *CubicDownSampleFilter;
    ConvFilter *EdgeDetectionFilter;
    FastImage *tmpIn;

public:
    C2();
    ~C2();
    virtual void filter(FastImage *bufferIn, FastImage *bufferOut);
};

#endif // C2_H
