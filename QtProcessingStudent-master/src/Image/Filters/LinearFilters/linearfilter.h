#ifndef LINEARFILTER
#define LINEARFILTER

#include "../filter.h"

class LinearFilter : public Filter {
protected :
    double *coeffs;

public :

    LinearFilter();

    virtual ~LinearFilter();

    void setCoeffs(double *coeffs);

    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};









#endif // LINEARFILTER

