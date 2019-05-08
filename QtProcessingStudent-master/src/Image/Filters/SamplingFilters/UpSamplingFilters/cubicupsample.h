#ifndef CUBICUPSAMPLE_H
#define CUBICUPSAMPLE_H

#include "upsamplingfilter.h"

class CubicUpSample : public UpSamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // CUBICUPSAMPLE

