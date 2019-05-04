#include "redchannel.h"

RedChannel::RedChannel() : LinearFilter() {
    double redKernel[][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    setCoeffs(redKernel);
}


