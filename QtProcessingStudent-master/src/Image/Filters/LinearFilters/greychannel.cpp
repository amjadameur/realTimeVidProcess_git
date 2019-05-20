#include "greychannel.h"

GreyChannel::GreyChannel() : LinearFilter() {
    filterName = "Grey Channel";
    double a = 0.33;
    double greyKernel[] = {a, a, a,
                           a, a, a,
                           a, a, a};
    setCoeffs(greyKernel);
}


