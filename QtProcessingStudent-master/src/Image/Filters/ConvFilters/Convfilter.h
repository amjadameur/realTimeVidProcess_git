#include "../filter.h"

#ifndef CONVFILTER_H
#define CONVFILTER_H


class ConvFilter : public Filter {
protected :
    int (*matrix)[3];
    int coeff;

public :
    ConvFilter();
    ~ConvFilter();


    void setMatrix(int matrix[][3]);

    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};









#endif // CONVFILTER

