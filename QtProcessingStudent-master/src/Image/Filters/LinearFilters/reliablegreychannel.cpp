#include "reliablegreychannel.h"

ReliableGreyChannel::ReliableGreyChannel() : LinearFilter() {
    filterName = "Reliable Grey Channel";
    double a = 0.299; double b = 0.587; double c = 0.114;
    double reliableGreyKernel[] = {a, b, c,
                                   a, b, c,
                                   a, b, c};
    setCoeffs(reliableGreyKernel);
}

