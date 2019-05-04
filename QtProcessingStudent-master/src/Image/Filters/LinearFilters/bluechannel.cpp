#include "bluechannel.h"

BlueChannel::BlueChannel() :  LinearFilter() {
    double blueKernel[][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    setCoeffs(blueKernel);
}



