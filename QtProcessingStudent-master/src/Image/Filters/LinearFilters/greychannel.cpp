#include "greychannel.h"

GreyChannel::GreyChannel() : LinearFilter() {
    double a = 0.33;
    double greyKernel[][3] = {{a, a, a}, {a, a, a}, {a, a, a}};
    setCoeffs(greyKernel);
}


