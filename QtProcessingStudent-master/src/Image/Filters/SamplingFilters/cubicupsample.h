#include "samplingfilter.h"

#ifndef CUBICUPSAMPLE_H
#define CUBICUPSAMPLE_H

class CubicUpSample : public SamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // CUBICUPSAMPLE

