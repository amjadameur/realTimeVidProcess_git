#ifndef LINEARDOWNSAMPLE
#define LINEARDOWNSAMPLE

#include "downsamplingfilter.h"

class LinearDownSample : public DownSamplingFilter {

public :
    LinearDownSample();
    virtual void rgbCompute(FastImage *bufferIn, int y, int x);
};


#endif // LINEARDOWNSAMPLE

