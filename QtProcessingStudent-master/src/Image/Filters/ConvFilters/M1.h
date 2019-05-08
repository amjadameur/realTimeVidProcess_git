#include "Convfilter.h"

#ifndef M1
#define M1


class m1 : public ConvFilter {
private :

public :
    explicit m1();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M1F

