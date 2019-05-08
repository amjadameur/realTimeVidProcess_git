#include "M0.h"

m0::m0() : ConvFilter() {
    int _intF = 0;
    setIntFilter(_intF);
}

FastImage* m0::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
