#include "greenchannel.h"

GreenChannel::GreenChannel() : LinearFilter() {
    filterName = "Green Channel";
}

void GreenChannel::rgbCompute() {

    *ptrOut++ = (*(unsigned int*) ptrIn) & 0xFF00FF00;

    ptrIn += 4;
}
