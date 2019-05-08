#ifndef LINEARUPSAMPLE_H
#define LINEARUPSAMPLE_H

#include "upsamplingfilter.h"

class LinearUpSample : public UpSamplingFilter {

public :
    virtual void rgbCompute(FastImage* bufferIn, int x, int y);
};

#endif // LINEARUPSAMPLE

