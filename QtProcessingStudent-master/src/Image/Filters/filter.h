#ifndef FILTER
#define FILTER

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "../FImage.h"

using namespace std;

#define imInR(y, x)      (bufferIn->Red(y, x))
#define imInG(y, x)      (bufferIn->Green(y, x))
#define imInB(y, x)      (bufferIn->Blue(y, x))

#define imOutR(y, x, v)  (bufferOut->Red(y, x, v)  )
#define imOutG(y, x, v)  (bufferOut->Green(y, x, v))
#define imOutB(y, x, v)  (bufferOut->Blue(y, x, v) )

#define tmpOutR(y, x, v) (tmpOut->Red(y, x, v)  )
#define tmpOutG(y, x, v) (tmpOut->Green(y, x, v))
#define tmpOutB(y, x, v) (tmpOut->Blue(y, x, v) )

class Filter {
protected :
    int rVal, gVal, bVal;

public :
    virtual void filter(FastImage *bufferIn, FastImage *bufferOut) = 0;
    virtual ~Filter() {} ;
};


#endif // FILTER

