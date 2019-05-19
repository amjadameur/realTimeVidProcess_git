#ifndef AUTOADAPT_H
#define AUTOADAPT_H

#include "../filter.h"

class AutoAdapt : public Filter {
private :
    int minR, minG, minB, maxR, maxG, maxB;
    double cuR, cuG, cuB;
public :
    AutoAdapt();

    void findMinMax(FastImage *bufferIn);
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};

#endif // AUTOADAPT

