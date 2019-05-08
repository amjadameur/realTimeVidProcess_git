#ifndef UPSAMPLINGFILTER_H
#define UPSAMPLINGFILTER_H

#include "../samplingfilter.h"

class UpSamplingFilter : public SamplingFilter {
protected :
    int rVal, gVal, bVal;

public:
    virtual FastImage* fastImageResize(FastImage *bufferIn);
    void rgbAssign(FastImage* bufferOut, int y, int x);
};

#endif // UPSAMPLINGFILTER_H
