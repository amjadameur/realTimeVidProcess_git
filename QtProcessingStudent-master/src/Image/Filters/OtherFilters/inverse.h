#ifndef INVERSE_H
#define INVERSE_H

#include "../filter.h"

class Inverse : public Filter {

public :
    Inverse();
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};


#endif

