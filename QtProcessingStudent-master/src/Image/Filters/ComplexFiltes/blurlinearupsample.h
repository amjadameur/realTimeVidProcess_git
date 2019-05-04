#ifndef BLURLINEARUPSAMPLE
#define BLURLINEARUPSAMPLE

#include "../SamplingFilters/linearupsample.h"
#include "../SamplingFilters/lineardownsample.h"
#include "../LinearFilters/reliablegreychannel.h"
#include "../OtherFilters/blur.h"

class BlurLinearUpSample  {
protected :    
    FastImage* tmp1;
    FastImage* tmp2;

    Blur blurFilter;
    ReliableGreyChannel reliableGreyFilter;
    LinearUpSample linearUpSampleFilter;
    LinearDownSample linearDownSampleFilter;

public :
    BlurLinearUpSample();
    ~BlurLinearUpSample();

    void refreshTmp();
    void filter(FastImage* previousBuffer2, FastImage* previousBuffer1,
                FastImage* bufferIn, FastImage* bufferOut);
};


#endif // BLURLINEARUPSAMPLE

