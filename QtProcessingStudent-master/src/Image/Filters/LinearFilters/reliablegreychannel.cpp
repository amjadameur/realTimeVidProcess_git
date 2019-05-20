#include "reliablegreychannel.h"

ReliableGreyChannel::ReliableGreyChannel() : LinearFilter() {
    filterName = "Reliable Grey Channel";

    coeff1 = 0.299;
    coeff2 = 0.587;
    coeff3 = 0.114;
}

