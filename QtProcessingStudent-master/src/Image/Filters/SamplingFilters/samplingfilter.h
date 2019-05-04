#include "../defines.h"
#include <cmath>

#ifndef SAMPLINGFILTER
#define SAMPLINGFILTER

class SamplingFilter {

public :
    void reduceImSize(FastImage* bufferIn, FastImage* bufferOut); // Decrease Image Size
    void increaseImSize(FastImage* bufferIn, FastImage* bufferOut); // Increase Image Size

};





#endif // SAMPLINGFILTER

