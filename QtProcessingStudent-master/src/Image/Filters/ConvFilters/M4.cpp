#include "M4.h"

m4::m4() : ConvFilter() {
    int _intF = 4;
    setIntFilter(_intF);
}

FastImage* m4::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
