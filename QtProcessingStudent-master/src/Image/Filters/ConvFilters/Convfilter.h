#include "../filter.h"

#ifndef CONVFILTER_H
#define CONVFILTER_H


class ConvFilter : public Filter {
protected :
    int intFilter;
    int *matrix;
    int coeff;

public :
    ConvFilter(int _matrix[9]);
    ConvFilter(int _intFilter);
    ConvFilter();

    ~ConvFilter();

    void setIntFilter(int _intF);
    void setFilter(int _intFilter);
    void initMatrix(void);
    void setMatrix(int _matrix[9]);

    void adjustImage(FastImage* _bufferIn, FastImage* _bufferOut);
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};









#endif // CONVFILTER

