#ifndef DOWNSAMPLE
#define DOWNSAMPLE

#include "downsamplingfilter.h"

class DownSample : public DownSamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // DOWNSAMPLE

