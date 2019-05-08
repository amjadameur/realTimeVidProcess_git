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
            rVal = 0; gVal = 0; bVal = 0;

            if(XYOutOfRange(x, y, width, height)) {
                rVal = imInR(y, x);
                gVal = imInG(y, x);
                bVal = imInB(y, x);

                imOutR(y,x, rVal);
                imOutG(y,x, gVal);
                imOutB(y,x, bVal);

            } else {
                for(int i = 0; i<3; i++) {
                    for(int j = 0; j<3; j++) {
                        rVal += matrix[i][j] * imInR(y+i-1, x+j-1);
                        gVal += matrix[i][j] * imInG(y+i-1, x+j-1);
                        bVal += matrix[i][j] * imInB(y+i-1, x+j-1);
                    }
                }

                rVal = (int) rVal/coeff;
                gVal = (int) gVal/coeff;
                bVal = (int) bVal/coeff;

                imOutR(y,x, rVal);
                imOutG(y,x, gVal);
                imOutB(y,x, bVal);

            }
        }
}

