#include "B2.h"

b2::b2() : ConvFilter() {
    int _intF = 12;
    setIntFilter(_intF);
}

FastImage* b2::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}

