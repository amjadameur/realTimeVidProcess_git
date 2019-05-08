#include "B1.h"

b1::b1() : ConvFilter() {
    int _intF = 11;
    setIntFilter(_intF);
}

FastImage* b1::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
