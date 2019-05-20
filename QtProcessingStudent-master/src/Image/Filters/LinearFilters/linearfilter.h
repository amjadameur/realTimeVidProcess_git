#ifndef LINEARFILTER
#define LINEARFILTER

#include "../filter.h"

class LinearFilter : public Filter {
protected :

    unsigned char *ptrIn ; // pointeur 8  bits sur l'image d'entrée
    unsigned int  *ptrOut; // pointe   32 bits sur l'image de sortie

    // coeffs du filtre linéaire
    double coeff1, coeff2, coeff3;

public :

    virtual void rgbCompute();
    virtual void filter(FastImage* bufferIn, FastImage* bufferOut);
};









#endif // LINEARFILTER

