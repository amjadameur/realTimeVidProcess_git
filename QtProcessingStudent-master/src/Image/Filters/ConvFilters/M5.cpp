#include "M5.h"

m5::m5() : ConvFilter() {
    int _intF = 5;
    setIntFilter(_intF);
}

FastImage* m5::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
