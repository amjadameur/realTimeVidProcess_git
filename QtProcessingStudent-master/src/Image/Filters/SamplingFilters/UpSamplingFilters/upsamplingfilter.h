#ifndef UPSAMPLINGFILTER_H
#define UPSAMPLINGFILTER_H

#include "../../filter.h"

class UpSamplingFilter : public Filter {
protected :
    int rVal, gVal, bVal;

public:
    FastImage *increaseImSize(FastImage *bufferIn);

    virtual void rgbCompute(FastImage* bufferIn, int x, int y) = 0;

    void rgbAssign(FastImage* bufferOut, int x, int y);

    virtual void filter(FastImage *bufferIn, FastImage *bufferOut);
};

#endif // UPSAMPLINGFILTER_H
