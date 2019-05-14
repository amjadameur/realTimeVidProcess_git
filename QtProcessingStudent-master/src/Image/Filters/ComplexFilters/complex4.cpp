#include "complex4.h"

C4::C4() {
    filterName = "C4";
}

void C4::filter(FastImage *bufferIn, FastImage *bufferOut) {
    bufferOut->FastImageCpy(bufferIn); // to discard
    // to be completed
}
