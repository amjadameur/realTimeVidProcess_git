#include "Convfilter.h"

#ifndef B0
#define B0


class b0 : public ConvFilter {
private :

public :
    //explicit B0(FastImage* bufferIn, FastImage* bufferOut, int _matrix[9], int _coeff);
    //explicit B0(FastImage* bufferIn, FastImage* bufferOut, int _intFilter, int _coeff);
    b0();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // B0F

