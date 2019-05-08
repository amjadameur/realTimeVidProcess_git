#include "M9.h"

m9::m9() : ConvFilter() {
    int _intF = 9;
    setIntFilter(_intF);
}

FastImage* m9::filter(FastImage* _bufferIn, FastImage* _bufferOut) {
    //cout << "access OK!" << endl;
    applyFilter(_bufferIn, _bufferOut);
    return _bufferOut;
}
