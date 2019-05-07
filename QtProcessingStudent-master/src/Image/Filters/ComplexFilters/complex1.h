#ifndef COMPLEX1
#define COMPLEX1

#include "../filter.h"

#include "../SamplingFilters/cubicdownsample.h"

class Complex1 {
protected :
    CubicDownSample cubicDownSampleFilter;

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // DOUBLECUBICDOWNSAMPLE

