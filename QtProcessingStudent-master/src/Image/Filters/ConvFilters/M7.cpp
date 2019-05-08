#include "M7.h"

m7::m7() : ConvFilter() {
    int _intF = 7;
    setIntFilter(_intF);
}

FastImage* m7::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
