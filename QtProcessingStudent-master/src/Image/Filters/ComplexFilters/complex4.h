#ifndef C4_H
#define C4_H

#include "../filter.h"

class C4 : public Filter {

public:
    C4();
    virtual void filter(FastImage *bufferIn, FastImage *bufferOut);
};

#endif // C4_H
