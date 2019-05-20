#include "linearfilter.h"

#ifndef BLUECHANNEL
#define BLUECHANNEL


class BlueChannel : public LinearFilter {

public :
    BlueChannel();
    virtual void rgbCompute();
};


#endif // BLUECHANNEL

