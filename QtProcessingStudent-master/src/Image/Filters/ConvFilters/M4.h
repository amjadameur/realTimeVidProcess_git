#include "Convfilter.h"

#ifndef M4
#define M4


class m4 : public ConvFilter {
private :

public :
    explicit m4();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M4F
