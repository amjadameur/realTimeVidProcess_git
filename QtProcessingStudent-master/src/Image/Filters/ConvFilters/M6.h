#include "Convfilter.h"

#ifndef M6
#define M6


class m6 : public ConvFilter {
private :

public :
    explicit m6();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M6F
