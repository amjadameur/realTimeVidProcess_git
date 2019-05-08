#ifndef COMPLEX1_H
#define COMPLEX1_H

#include "../filter.h"

#include "../SamplingFilters/DownSamplingFilters/cubicdownsample.h"

class C1 : public Filter {
private :
    FastImage *tmpIn;

    CubicDownSample cubicDownSampleFilter;

public :
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // DOUBLECUBICDOWNSAMPLE

