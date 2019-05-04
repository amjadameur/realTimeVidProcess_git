#include "../filter.h"

#ifndef LINEARFILTER
#define LINEARFILTER


class LinearFilter {
protected :
    double (*coeffs)[3];

public :

    LinearFilter();

    ~LinearFilter();

    void initCoeffs(void);
    void setCoeffs(double _Coeffs[][3]);

    void filter(FastImage* bufferIn, FastImage* bufferOut);
};









#endif // LINEARFILTER

