#include "B0.h"

b0::b0() : ConvFilter() {
    int _intF = 10;
    setIntFilter(_intF);
}

FastImage* b0::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}

