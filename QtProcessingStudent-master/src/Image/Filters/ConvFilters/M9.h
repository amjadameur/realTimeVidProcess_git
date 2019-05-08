#include "Convfilter.h"

#ifndef M9
#define M9


class m9 : public ConvFilter {
private :

public :
    explicit m9();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // M9F
