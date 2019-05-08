#ifndef SAMPLINGFILTER_H
#define SAMPLINGFILTER_H

#include "../filter.h"

class SamplingFilter : public Filter {

public:
    virtual FastImage* fastImageResize(FastImage *bufferIn)    = 0;
    virtual void rgbCompute(FastImage* bufferIn, int y, int x) = 0;
    virtual void rgbAssign(FastImage* bufferOut, int y, int x) = 0;

    bool XYOutOfRange(FastImage *bufferIn, int y, int x);
    virtual void filter(FastImage *bufferIn, FastImage *bufferOut);
};

#endif // SAMPLINGFILTER_H
