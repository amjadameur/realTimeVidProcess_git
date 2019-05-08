#ifndef COMPLEX1
#define COMPLEX1

#include "../filter.h"

#include "../SamplingFilters/cubicdownsample.h"

class Complex1 : public Filter {
private :
    FastImage *tmpIn;

    CubicDownSample cubicDownSampleFilter;

public :
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // DOUBLECUBICDOWNSAMPLE

