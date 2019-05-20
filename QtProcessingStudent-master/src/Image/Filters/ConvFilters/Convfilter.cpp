#include "Convfilter.h"

ConvFilter::ConvFilter() {
    matrix = new int[3][3];
}

void ConvFilter::setMatrix(int matrix[][3]) {
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            this->matrix[i][j] = matrix[i][j];
        }
    }
}

ConvFilter::~ConvFilter() {
    delete matrix;
}

bool XYOutOfRange(int x, int y, int width, int height) {
    if ((x-1<0) || (y-1<0) || (x+1>width) || (y+1>height)) return true;
    return false;
}


void ConvFilter::filter(FastImage* bufferIn, FastImage* bufferOut) {

    int width  = bufferIn->width();
    int height = bufferIn->height();

    for(int y = 0; y < height; y++)
        for(int x= 0; x< width; x++)
        {
            if(XYOutOfRange(x, y, width, height)) {
                rOut = imInR(y, x);
                gOut = imInG(y, x);
                bOut = imInB(y, x);

                imOutR(y,x, rOut);
                imOutG(y,x, gOut);
                imOutB(y,x, bOut);

            } else {
                rOut = 0; gOut = 0; bOut = 0;

                for(int i = 0; i<3; i++) {
                    for(int j = 0; j<3; j++) {
                        rOut += matrix[i][j] * imInR(y+i-1, x+j-1);
                        gOut += matrix[i][j] * imInG(y+i-1, x+j-1);
                        bOut += matrix[i][j] * imInB(y+i-1, x+j-1);
                    }
                }

                rOut = rOut/coeff;
                gOut = gOut/coeff;
                bOut = bOut/coeff;

                imOutR(y, x, rOut);
                imOutG(y, x, gOut);
                imOutB(y, x, bOut);

            }
        }
}

