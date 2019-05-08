#ifndef COMPLEX3_H
#define COMPLEX3_H

#include "../filter.h"

#include "../SamplingFilters/upsample.h"
#include "../SamplingFilters/linearupsample.h"
#include "../LinearFilters/reliablegreychannel.h"
#include "../OtherFilters/blur.h"

class C3 : public Filter {
private :
    FastImage *tmpIn;

    Blur *blurFilter;
    ReliableGreyChannel reliableGreyFilter;
    LinearUpSample linearUpSampleFilter;

    UpSample       UpSampleFilter;

public :
    C3(Blur *_blurFilter);
    virtual void filter(FastImage *bufferIn, FastImage* bufferOut);
};


#endif // BLURLINEARUPSAMPLE

