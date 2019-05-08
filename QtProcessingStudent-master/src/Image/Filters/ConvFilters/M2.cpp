#include "M2.h"

m2::m2() : ConvFilter() {
    int _intF = 2;
    setIntFilter(_intF);
}

FastImage* m2::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
