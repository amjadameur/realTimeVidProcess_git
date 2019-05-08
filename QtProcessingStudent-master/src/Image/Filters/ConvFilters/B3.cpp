#include "B3.h"

b3::b3() : ConvFilter() {
    int _intF = 13;
    setIntFilter(_intF);
}

FastImage* b3::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
