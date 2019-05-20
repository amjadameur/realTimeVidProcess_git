#include "linearfilter.h"

#ifndef REDCHANNEL
#define REDCHANNEL

class RedChannel : public LinearFilter {

public :
    RedChannel();
    virtual void rgbCompute();
};




#endif // REDCHANNEL

