#ifndef LINEARFILTER
#define LINEARFILTER

#include "../filter.h"

class LinearFilter : public Filter {
protected :
    double (*coeffs)[3];

public :

    LinearFilter();

    virtual ~LinearFilter();

    void setCoeffs(double _Coeffs[][3]);

    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};









#endif // LINEARFILTER

