#ifndef CUBICDOWNSAMPLE
#define CUBICDOWNSAMPLE

#include "downsamplingfilter.h"

class CubicDownSample : public DownSamplingFilter {

public :
    CubicDownSample();
    virtual void rgbCompute(FastImage* bufferIn, int y, int x);
};


#endif // CUBICDOWNSAMPLE

