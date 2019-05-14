#include "bluechannel.h"

BlueChannel::BlueChannel() :  LinearFilter() {
    filterName = "Blue Channel";
    double blueKernel[][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    setCoeffs(blueKernel);
}



