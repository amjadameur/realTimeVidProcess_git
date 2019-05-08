#ifndef DOWNSAMPLINGFILTER_H
#define DOWNSAMPLINGFILTER_H

#include "../../filter.h"

class DownSamplingFilter : public Filter {
protected :
    int rVal, gVal, bVal;

public:
    FastImage* decreaseImSize(FastImage* bufferIn);
    virtual void rgbCompute(FastImage* bufferIn, int x, int y) = 0;
    virtual void filter(FastImage *bufferIn, FastImage *bufferOut);
};

#endif // DOWNSAMPLINGFILTER_H
