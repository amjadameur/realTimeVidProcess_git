#ifndef C2_H
#define C2_H

#include "../filter.h"

class C2 : public Filter {

public:
    C2();
    virtual void filter(FastImage *bufferIn, FastImage *bufferOut);
};

#endif // C2_H
