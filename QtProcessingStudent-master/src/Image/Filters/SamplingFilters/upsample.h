#include "samplingfilter.h"

#ifndef UPSAMPLE_H
#define UPSAMPLE_H

class UpSample : public SamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // UPSAMPLE

