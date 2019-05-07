#ifndef COMPLEX1
#define COMPLEX1

#include "../filter.h"

#include "../SamplingFilters/cubicdownsample.h"

class Complex1 {
private :
    FastImage *tmpIn;

    CubicDownSample cubicDownSampleFilter;

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // DOUBLECUBICDOWNSAMPLE

