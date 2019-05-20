#include "greychannel.h"

GreyChannel::GreyChannel() : LinearFilter() {
    filterName = "Grey Channel";
    coeff1 = 0.33;
    coeff2 = 0.33;
    coeff3 = 0.33;
}


