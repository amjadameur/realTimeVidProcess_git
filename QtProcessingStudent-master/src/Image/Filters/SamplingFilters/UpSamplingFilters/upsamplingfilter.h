#ifndef UPSAMPLINGFILTER_H
#define UPSAMPLINGFILTER_H

#include "../../filter.h"

class UpSamplingFilter : public Filter {
public:
    FastImage *increaseImSize(FastImage *bufferIn);
};

#endif // UPSAMPLINGFILTER_H
