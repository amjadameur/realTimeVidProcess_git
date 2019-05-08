#ifndef DOWNSAMPLINGFILTER_H
#define DOWNSAMPLINGFILTER_H

#include "../samplingfilter.h"
#include <math.h>

class DownSamplingFilter : public SamplingFilter {
protected :
    int rVal, gVal, bVal;

public:
    FastImage* fastImageResize(FastImage* bufferIn);
    virtual void rgbAssign (FastImage* bufferOut, int y, int x);
};

#endif // DOWNSAMPLINGFILTER_H
