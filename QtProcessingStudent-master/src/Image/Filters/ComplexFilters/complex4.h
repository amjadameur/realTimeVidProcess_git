#ifndef C4_H
#define C4_H

#include "../filter.h"
#include "../ConvFilters/B3.h"
#include "../LinearFilters/greychannel.h"
#include "../ConvFilters/M3.h"


class C4 : public Filter {
private :
    ConvFilter   *EdgeDetectionFilter;
    LinearFilter *GreyChannelFilter;
    ConvFilter   *FlouFilter;
    FastImage    *tmpIn;

public:
    C4();
    ~C4();
    virtual void filter(FastImage *bufferIn, FastImage *bufferOut);
};

#endif // C4_H
