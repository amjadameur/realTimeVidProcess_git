#ifndef AUTOADAPT_H
#define AUTOADAPT_H

#include "../filter.h"

class AutoAdapt : public Filter {

public :
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // AUTOADAPT

