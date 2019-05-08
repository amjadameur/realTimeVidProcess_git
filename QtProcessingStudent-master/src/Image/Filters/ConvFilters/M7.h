#include "Convfilter.h"

#ifndef M7
#define M7


class m7 : public ConvFilter {
private :

public :
    explicit m7();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M7F
