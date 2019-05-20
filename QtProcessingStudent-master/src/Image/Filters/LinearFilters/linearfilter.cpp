#include "linearfilter.h"



void LinearFilter::setCoeffs(double _coeffs[][3]) {
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            coeffs[i][j] = _coeffs[i][j];
        }
    }
}


LinearFilter::LinearFilter()  {
    coeffs = new double[3][3];
}


LinearFilter::~LinearFilter() {
    delete coeffs;
}

void LinearFilter::filter(FastImage* bufferIn, FastImage* bufferOut) {
    //unsigned char rIn, gIn, bIn;
    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            rVal = (int) coeffs[0][0]*imInR(y,x) + coeffs[0][1]*imInG(y,x) + coeffs[0][2]*imInB(y,x);
            gVal = (int) coeffs[1][0]*imInR(y,x) + coeffs[1][1]*imInG(y,x) + coeffs[1][2]*imInB(y,x);
            bVal = (int) coeffs[2][0]*imInR(y,x) + coeffs[2][1]*imInG(y,x) + coeffs[2][2]*imInB(y,x);

            imOutR(y, x, rVal);
            imOutG(y, x, gVal);
            imOutB(y, x, bVal);
        }
    }
}


































