#ifndef LINEARFILTER
#define LINEARFILTER

#include "../filter.h"

class LinearFilter : public Filter {
protected :
    unsigned char rIn, gIn, bIn;

    unsigned char *ptrIn ;
    unsigned int  *ptrOut;

    double coeff1, coeff2, coeff3;

public :

    LinearFilter();
    virtual ~LinearFilter();
    void setCoeffs(double *coeffs);

    virtual void rgbCompute();
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};









#endif // LINEARFILTER

