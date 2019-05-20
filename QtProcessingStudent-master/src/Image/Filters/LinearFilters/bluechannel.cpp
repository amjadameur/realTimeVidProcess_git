#include "bluechannel.h"

BlueChannel::BlueChannel() :  LinearFilter() {
    filterName = "Blue Channel";
}

void BlueChannel::rgbCompute() {

    *ptrOut++ = (*(unsigned int*) ptrIn) & 0xFF0000FF;

    ptrIn += 4;
}



