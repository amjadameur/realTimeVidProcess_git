#include "Convfilter.h"

#ifndef B3
#define B3


class b3 : public ConvFilter {
private :

public :
    //explicit B3(FastImage* bufferIn, FastImage* bufferOut, int _matrix[9], int _coeff);
    //explicit B3(FastImage* bufferIn, FastImage* bufferOut, int _intFilter, int _coeff);
    explicit b3();
    FastImage* filter(FastImage* _bufferIn, FastImage* _bufferOut);

};

#endif // B3F

