#include "greenchannel.h"

GreenChannel::GreenChannel() : LinearFilter() {
    double greenKernel[][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    setCoeffs(greenKernel);
}

