#include "M8.h"

m8::m8() : ConvFilter() {
    int _intF = 8;
    setIntFilter(_intF);
}

FastImage* m8::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
