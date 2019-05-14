#ifndef UPSAMPLE_H
#define UPSAMPLE_H

#include "upsamplingfilter.h"

class UpSample : public UpSamplingFilter {

public :
    UpSample();
    virtual void rgbCompute(FastImage* bufferIn, int y, int x);
};


#endif // UPSAMPLE

