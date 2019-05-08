#ifndef UPSAMPLE_H
#define UPSAMPLE_H

#include "upsamplingfilter.h"

class UpSample : public UpSamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // UPSAMPLE

