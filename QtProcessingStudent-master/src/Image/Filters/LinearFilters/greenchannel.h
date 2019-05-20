#include "linearfilter.h"

#ifndef GREENCHANNEL
#define GREENCHANNEL

class GreenChannel : public LinearFilter {

public :
    GreenChannel();
    virtual void rgbCompute();
};



#endif // GREENCHANNEL

