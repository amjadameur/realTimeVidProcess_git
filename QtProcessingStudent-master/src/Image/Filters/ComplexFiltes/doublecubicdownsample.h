#include "../SamplingFilters/cubicdownsample.h"

#ifndef DOUBLECUBICDOWNSAMPLE
#define DOUBLECUBICDOWNSAMPLE

class DoubleCubicDownSample {
protected :
    CubicDownSample cubicDownSampleFilter;

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // DOUBLECUBICDOWNSAMPLE

