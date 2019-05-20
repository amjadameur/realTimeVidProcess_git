#include "redchannel.h"

RedChannel::RedChannel() : LinearFilter() {
    filterName = "Red Channel";
    double redKernel[] = {1, 0, 0,
                          0, 0, 0,
                          0, 0, 0};
    setCoeffs(redKernel);
}


