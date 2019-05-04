#include "samplingfilter.h"

#ifndef CUBICUPSAMPLE
#define CUBICUPSAMPLE

class CubicUpSample : public SamplingFilter {

public :
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // CUBICUPSAMPLE

