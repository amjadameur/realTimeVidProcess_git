#ifndef COMPLEX3
#define COMPLEX3

#include "../filter.h"

#include "../SamplingFilters/linearupsample.h"
#include "../LinearFilters/reliablegreychannel.h"
#include "../OtherFilters/blur.h"

class Complex3  {
private :
    FastImage *tmpIn;

    Blur *blurFilter;
    ReliableGreyChannel reliableGreyFilter;
    LinearUpSample linearUpSampleFilter;

public :
    Complex3(Blur *blurFilter);
    void filter(FastImage *bufferIn, FastImage* bufferOut);
};


#endif // BLURLINEARUPSAMPLE

