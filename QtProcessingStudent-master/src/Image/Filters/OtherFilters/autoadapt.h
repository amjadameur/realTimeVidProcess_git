#ifndef AUTOADAPT_H
#define AUTOADAPT_H

#include "../filter.h"

class AutoAdapt : public Filter {

public :
    AutoAdapt();
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // AUTOADAPT

