#include "samplingfilter.h"

#ifndef LINEARDOWNSAMPLE
#define LINEARDOWNSAMPLE

class LinearDownSample : public SamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // LINEARDOWNSAMPLE

