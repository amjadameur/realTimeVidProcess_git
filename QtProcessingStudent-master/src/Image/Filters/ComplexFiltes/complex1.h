#ifndef DOUBLECUBICDOWNSAMPLE
#define DOUBLECUBICDOWNSAMPLE

#include "../SamplingFilters/cubicdownsample.h"

class DoubleCubicDownSample {
protected :
    CubicDownSample cubicDownSampleFilter;

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // DOUBLECUBICDOWNSAMPLE

