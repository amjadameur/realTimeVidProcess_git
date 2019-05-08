#include "M3.h"

m3::m3() : ConvFilter() {
    int _intF = 3;
    setIntFilter(_intF);
}

FastImage* m3::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
