#ifndef CUBICUPSAMPLE_H
#define CUBICUPSAMPLE_H

#include "upsamplingfilter.h"

class CubicUpSample : public UpSamplingFilter {

public :
    virtual void rgbCompute(FastImage* bufferIn, int y, int x);
};


#endif // CUBICUPSAMPLE

