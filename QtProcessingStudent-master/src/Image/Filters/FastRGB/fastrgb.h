#ifndef FASTRGB_H
#define FASTRGB_H

#include "../filter.h"

class FastRGB : public Filter {
protected :
    unsigned int rgbMask;
    // 0xAARRGGBB , A : alpha, R : Red, G : green, B : blue

public:

    virtual void filter(FastImage *bufferIn, FastImage *bufferOut);
};

#endif // FASTRGB_H
