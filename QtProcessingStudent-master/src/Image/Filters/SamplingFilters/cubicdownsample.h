#include "samplingfilter.h"

#ifndef CUBICDOWNSAMPLE
#define CUBICDOWNSAMPLE


class CubicDownSample : public SamplingFilter {

public :

    void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif // CUBICDOWNSAMPLE

