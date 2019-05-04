#include "samplingfilter.h"

#ifndef DOWNSAMPLE
#define DOWNSAMPLE


class DownSample : public SamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // DOWNSAMPLE

