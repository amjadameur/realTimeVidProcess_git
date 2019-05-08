#ifndef LINEARUPSAMPLE_H
#define LINEARUPSAMPLE_H

#include "upsamplingfilter.h"

class LinearUpSample : public UpSamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // LINEARUPSAMPLE

