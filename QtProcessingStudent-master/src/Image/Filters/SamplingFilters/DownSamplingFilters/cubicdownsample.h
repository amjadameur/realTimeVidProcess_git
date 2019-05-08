#ifndef CUBICDOWNSAMPLE
#define CUBICDOWNSAMPLE

#include "downsamplingfilter.h"

class CubicDownSample : public DownSamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // CUBICDOWNSAMPLE

