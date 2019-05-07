#ifndef BLUR
#define BLUR

#include "../filter.h"

class Blur {
    FastImage *prevIm1;
    FastImage *prevIm2;

public :
    Blur();
    ~Blur();
    void refreshPrevIm(FastImage* bufferIn);
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // BLUR

