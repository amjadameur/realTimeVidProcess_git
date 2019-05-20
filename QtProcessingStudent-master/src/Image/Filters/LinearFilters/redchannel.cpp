#include "redchannel.h"

RedChannel::RedChannel() : LinearFilter() {
    filterName = "Red Channel";
}

void RedChannel::rgbCompute() {

    *ptrOut++ = (*(unsigned int*) ptrIn) & 0xFFFF0000;

    ptrIn += 4;
}
