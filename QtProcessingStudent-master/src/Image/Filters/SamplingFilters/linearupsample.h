#include "samplingfilter.h"

#ifndef LINEARUPSAMPLE_H
#define LINEARUPSAMPLE_H

class LinearUpSample : public SamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // LINEARUPSAMPLE

