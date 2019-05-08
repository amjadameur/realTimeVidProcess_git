#ifndef BLUR_H
#define BLUR_H

#include "../filter.h"

class Blur : public Filter {
    FastImage *prevIm1;
    FastImage *prevIm2;

public :
    Blur();
    virtual ~Blur();
    void refreshPrevIm(FastImage *bufferIn);

    bool differentImSizes(FastImage *bufferIn);
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // BLUR

