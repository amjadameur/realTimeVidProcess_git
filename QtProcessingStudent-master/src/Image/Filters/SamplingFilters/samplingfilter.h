#ifndef SAMPLINGFILTER
#define SAMPLINGFILTER

#include "../filter.h"

#include <cmath>

#define tmpOutR(y, x, v) tmpOut->Red(y, x, v)
#define tmpOutG(y, x, v) tmpOut->Green(y, x, v)
#define tmpOutB(y, x, v) tmpOut->Blue(y, x, v)


class SamplingFilter {

public :
    FastImage* decreaseImSize(FastImage* bufferIn); // Decrease Image Size
    FastImage* increaseImSize(FastImage* bufferIn); // Increase Image Size
};





#endif // SAMPLINGFILTER

