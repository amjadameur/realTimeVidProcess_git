#include "greenchannel.h"

GreenChannel::GreenChannel() : LinearFilter() {
    filterName = "Green Channel";
    double greenKernel[] = {0, 0, 0,
                            0, 1, 0,
                            0, 0, 0};
    setCoeffs(greenKernel);
}

