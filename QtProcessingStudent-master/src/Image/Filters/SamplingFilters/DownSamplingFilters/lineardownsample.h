#ifndef LINEARDOWNSAMPLE
#define LINEARDOWNSAMPLE

#include "downsamplingfilter.h"

class LinearDownSample : public DownSamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // LINEARDOWNSAMPLE

