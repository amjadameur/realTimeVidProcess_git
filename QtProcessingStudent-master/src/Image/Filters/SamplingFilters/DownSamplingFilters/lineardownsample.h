#ifndef LINEARDOWNSAMPLE
#define LINEARDOWNSAMPLE

#include "downsamplingfilter.h"

class LinearDownSample : public DownSamplingFilter {

public :
    virtual void rgbCompute(FastImage *bufferIn, int y, int x);
};


#endif // LINEARDOWNSAMPLE

