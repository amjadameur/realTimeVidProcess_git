#ifndef COMPLEX3
#define COMPLEX3

#include "../filter.h"

#include "../SamplingFilters/upsample.h"
#include "../SamplingFilters/linearupsample.h"
#include "../LinearFilters/reliablegreychannel.h"
#include "../OtherFilters/blur.h"

class Complex3  {
private :
    FastImage *tmpIn;

    Blur *blurFilter;
    ReliableGreyChannel reliableGreyFilter;
    LinearUpSample linearUpSampleFilter;

    UpSample       UpSampleFilter;

public :
    Complex3(Blur *_blurFilter);
    void filter(FastImage *bufferIn, FastImage* bufferOut);
};


#endif // BLURLINEARUPSAMPLE

