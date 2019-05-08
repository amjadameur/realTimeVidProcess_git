#include "Convfilter.h"

#ifndef B2
#define B2


class b2 : public ConvFilter {
private :

public :
    //explicit B2(FastImage* bufferIn, FastImage* bufferOut, int _matrix[9], int _coeff);
    //explicit B2(FastImage* bufferIn, FastImage* bufferOut, int _intFilter, int _coeff);
    explicit b2();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // B2F

