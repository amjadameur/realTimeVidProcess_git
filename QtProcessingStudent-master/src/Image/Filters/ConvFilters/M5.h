#include "Convfilter.h"

#ifndef M5
#define M5


class m5 : public ConvFilter {
private :

public :
    explicit m5();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M5F
