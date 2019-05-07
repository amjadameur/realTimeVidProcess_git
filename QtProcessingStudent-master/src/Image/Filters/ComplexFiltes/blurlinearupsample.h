#ifndef BLURLINEARUPSAMPLE
#define BLURLINEARUPSAMPLE

#include "../SamplingFilters/linearupsample.h"
#include "../SamplingFilters/lineardownsample.h"
#include "../LinearFilters/reliablegreychannel.h"
#include "../LinearFilters/redchannel.h"
#include "../OtherFilters/blur.h"

class BlurLinearUpSample  {
    FastImage *tmpIn;

   // Blur *blurFilter;
    ReliableGreyChannel reliableGreyFilter;
   // LinearUpSample linearUpSampleFilter;
   RedChannel redChannelFilter;

public :
    BlurLinearUpSample();
    ~BlurLinearUpSample();
    void filter(FastImage *bufferIn, FastImage* bufferOut);
};


#endif // BLURLINEARUPSAMPLE

