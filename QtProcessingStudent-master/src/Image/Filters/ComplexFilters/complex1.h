#ifndef COMPLEX1_H
#define COMPLEX1_H

#include "../filter.h"

#include "../SamplingFilters/DownSamplingFilters/cubicdownsample.h"

class C1 : public Filter {
private :
    FastImage *tmpIn;

    DownSamplingFilter *cubicDownSampleFilter;

public :
    C1();
    ~C1();

    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // DOUBLECUBICDOWNSAMPLE

