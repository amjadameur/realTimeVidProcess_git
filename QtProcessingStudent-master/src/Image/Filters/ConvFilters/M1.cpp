#include "M1.h"

m1::m1() : ConvFilter() {
    int _intF = 1;
    setIntFilter(_intF);
}

FastImage* m1::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
