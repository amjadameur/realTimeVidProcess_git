#include "../filter.h"

#ifndef CONVFILTER
#define CONVFILTER


class ConvFilter {
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
    void applyFilter(FastImage* _bufferIn, FastImage* _bufferOut);
};









#endif // CONVFILTER

