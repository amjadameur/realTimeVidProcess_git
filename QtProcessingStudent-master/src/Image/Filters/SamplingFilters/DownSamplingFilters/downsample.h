#ifndef DOWNSAMPLE_H
#define DOWNSAMPLE_H

#include "downsamplingfilter.h"


class DownSample : public DownSamplingFilter {

public :
    virtual void rgbCompute(FastImage* bufferIn, int y, int x);
};


#endif // DOWNSAMPLE

