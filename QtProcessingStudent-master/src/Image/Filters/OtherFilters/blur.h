#ifndef BLUR
#define BLUR

#include "../defines.h"

class Blur {

public :
    void filter(FastImage* previousBuffer2, FastImage* previousBuffer1,
                      FastImage* bufferIn, FastImage* bufferOut);
};

#endif // BLUR

