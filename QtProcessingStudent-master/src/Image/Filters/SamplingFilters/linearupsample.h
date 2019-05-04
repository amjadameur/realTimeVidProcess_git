#include "samplingfilter.h"

#ifndef LINEARUPSAMPLE
#define LINEARUPSAMPLE

class LinearUpSample : public SamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // LINEARUPSAMPLE

