#include "complex2.h"

C2::C2()
{

}

void C2::filter(FastImage *bufferIn, FastImage *bufferOut) {
    bufferOut->FastImageCpy(bufferIn); // to discard
    // to be completed
}
