#include "../defines.h"

#ifndef BLUR
#define BLUR


class Blur {

public :
    void filter(FastImage* previousBuffer2, FastImage* previousBuffer1,
                      FastImage* bufferIn, FastImage* bufferOut);
};

#endif // BLUR

