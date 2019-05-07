#ifndef BLUR
#define BLUR

#include "../defines.h"

class Blur {
    FastImage *prevIm1;
    FastImage *prevIm2;
public :
    Blur();
    ~Blur();
    void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // BLUR

