#include "samplingfilter.h"

#ifndef UPSAMPLE
#define UPSAMPLE

class UpSample : public SamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // UPSAMPLE

