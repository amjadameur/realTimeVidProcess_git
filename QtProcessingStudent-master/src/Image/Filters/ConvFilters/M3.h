#include "Convfilter.h"

#ifndef M3
#define M3


class m3 : public ConvFilter {
private :

public :
    explicit m3();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M3F
