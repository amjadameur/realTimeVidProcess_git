#include "M6.h"

m6::m6() : ConvFilter() {
    int _intF = 6;
    setIntFilter(_intF);
}

FastImage* m6::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
