#include "Convfilter.h"

#ifndef M8
#define M8


class m8 : public ConvFilter {
private :

public :
    explicit m8();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M8F
