#include "Convfilter.h"

#ifndef M2
#define M2


class m2 : public ConvFilter {
private :

public :
    explicit m2();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M2F
