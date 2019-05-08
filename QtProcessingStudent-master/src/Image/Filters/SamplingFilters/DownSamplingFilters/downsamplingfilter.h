#ifndef DOWNSAMPLINGFILTER_H
#define DOWNSAMPLINGFILTER_H

#include "../../filter.h"

class DownSamplingFilter : public Filter {

public:
    FastImage* decreaseImSize(FastImage* bufferIn);
};

#endif // DOWNSAMPLINGFILTER_H
