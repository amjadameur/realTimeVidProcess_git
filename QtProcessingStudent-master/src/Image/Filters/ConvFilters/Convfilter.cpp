#include "Convfilter.h"

void ConvFilter::initMatrix(void) {
    for (int j = 0; j < 9; j++) {
        matrix = new int[9];
        matrix[j] = 0;
    }
}

void ConvFilter::setMatrix(int _matrix[9]) {
    for (int j = 0; j < 9; j++) {
        matrix = new int[9];
        matrix[j] = _matrix[j];
    }
}

void ConvFilter::setIntFilter(int _intF){
    intFilter = _intF;
}


ConvFilter::ConvFilter(int _matrix[9]) {
    coeff  = 1;
    setMatrix(_matrix);
    intFilter = 0;
}

ConvFilter::ConvFilter(int _intFilter) {
    coeff = 1;
    setFilter(_intFilter);
    intFilter = _intFilter;
}

ConvFilter::ConvFilter() {
    coeff = 1;
    initMatrix();
    intFilter = 0;
}


void ConvFilter::adjustImage(FastImage* _bufferIn, FastImage* _bufferOut) {
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( _bufferOut->width() != _bufferIn->width() || _bufferOut->height() != _bufferIn->height() ){
        _bufferOut->resize(_bufferIn->height(), _bufferIn->width());
    }
}

void ConvFilter::setFilter(int _intFilter) {
    if (_intFilter == 0) {
        matrix[0] = 0; matrix[1] = 0; matrix[2] = 0;
        matrix[3] = 0; matrix[4] = 1; matrix[5] = 0;
        matrix[6] = 0; matrix[7] = 0; matrix[8] = 0;
        coeff = 1;
    } else if (_intFilter == 1) { // M2
        matrix[0] = 0; matrix[1] = 0;  matrix[2] = 0;
        matrix[3] = 0; matrix[4] = 0;  matrix[5] = 0;
        matrix[6] = 0; matrix[7] = 0;  matrix[8] = 0;
        coeff = 1;
    } else if (_intFilter == 2) {  // M2
        matrix[0] = -1; matrix[1] = 0;  matrix[2] = 1;
        matrix[3] = -2; matrix[4] = 0;  matrix[5] = 2;
        matrix[6] = -1; matrix[7] = 0;  matrix[8] = 1;
        coeff = 1;
    } else if (_intFilter == 3) {  // M3
        matrix[0] = -1; matrix[1] = 0;  matrix[2] = 1;
        matrix[3] = -1; matrix[4] = 0;  matrix[5] = 1;
        matrix[6] = -1; matrix[7] = 0;  matrix[8] = 1;
        coeff = 1;
    } else if (_intFilter == 4) {  // M4
        matrix[0] = -1; matrix[1] = -2;  matrix[2] = -1;
        matrix[3] = 0; matrix[4] = 0;  matrix[5] = 0;
        matrix[6] = 1; matrix[7] = 2;  matrix[8] = 1;
        coeff = 1;
    } else if (_intFilter == 5) {   // M5
        matrix[0] = -1; matrix[1] = -1;  matrix[2] = -1;
        matrix[3] = 0; matrix[4] = 0;  matrix[5] = 0;
        matrix[6] = 1; matrix[7] = 1;  matrix[8] = 1;
        coeff = 1;
    } else if (_intFilter == 6) {  // M6
        matrix[0] = 0; matrix[1] = -1;  matrix[2] = 0;
        matrix[3] = -1; matrix[4] = 4;  matrix[5] = -1;
        matrix[6] = 0; matrix[7] = -1; matrix[8] = 0;
        coeff = 1;
    } else if (_intFilter == 7) {  // M7
        matrix[0] = -1; matrix[1] = -1; matrix[2] = -1;
        matrix[3] = -1; matrix[4] = 8 ; matrix[5] = -1;
        matrix[6] = -1; matrix[7] = -1; matrix[8] = -1;
        coeff = 1;
    } else if (_intFilter == 8) { // M8
        matrix[0] = -1; matrix[1] = -2; matrix[2] = -1;
        matrix[3] = -2; matrix[4] = 12; matrix[5] = -2;
        matrix[6] = -1; matrix[7] = -2; matrix[8] = -1;
        coeff = 1;
    } else if (_intFilter == 9) {   // M9
        matrix[0] = -1; matrix[1] = -1; matrix[2] = 0;
        matrix[3] = -1; matrix[4] =  0; matrix[5] = 1;
        matrix[6] =  0; matrix[7] =  1; matrix[8] = 1;
        coeff = 1;
    } else if (_intFilter == 10) {   // b0
        matrix[0] =  0; matrix[1] = 1; matrix[2] = 0;
        matrix[3] = 1; matrix[4] = 4; matrix[5] = 1;
        matrix[6] =  0; matrix[7] = 1; matrix[8] =  0;
        coeff = 8;
    } else if (_intFilter == 11) {   // b11/8
        matrix[0] = 1 ; matrix[1] = 2; matrix[2] = 1;
        matrix[3] = 2 ; matrix[4] = 8; matrix[5] = 2;
        matrix[6] = 1 ; matrix[7] = 2; matrix[8] = 1;
        coeff = 16;
    } else if (_intFilter == 12) {   // b2
        matrix[0] = 1; matrix[1] = 1; matrix[2] = 1;
        matrix[3] = 1; matrix[4] = 1; matrix[5] = 1;
        matrix[6] = 1; matrix[7] = 1; matrix[8] = 1;
        coeff = 9;
    } else if (_intFilter == 13) {   // b3
        matrix[0] = 0; matrix[1] = 0; matrix[2] = 0;
        matrix[3] = 0; matrix[4] = 1; matrix[5] = 0;
        matrix[6] = 0; matrix[7] = 0; matrix[8] = 0;
        coeff = 1;

    }else {
        matrix[0] = 1; matrix[1] = 1; matrix[2] = 1;
        matrix[3] = 1; matrix[4] =  0; matrix[5] = 1;
        matrix[6] = 1; matrix[7] = 1; matrix[8] = 1;
        coeff = 8;
        cout<< "Sorry, 0 definition of this filter !" << endl;
    }
}


void ConvFilter::applyFilter(FastImage* _bufferIn, FastImage* _bufferOut)
{
    setFilter(intFilter);
    //cout << intFilter << endl;
    //cout << coeff << matrix[0] << matrix[1] << matrix[2] << endl;
    //adjustImage();
    for(int y = 0; y < _bufferIn->height(); y++)
        for(int x= 0; x< 4 * _bufferIn->width(); x++)
        {
            if(y == 0 || x== 0 || y == _bufferIn->height() - 1 || x== 4 * (_bufferIn->width() - 1) || ((x== 1 || x== 2 || (x== 4*(_bufferIn->width()- 1) + 1 || (x== 4 * (_bufferIn->width() - 1) + 2))))) {
                _bufferOut->Red(y,x, _bufferIn->Red(y,x));
                _bufferOut->Blue(y,x, _bufferIn->Blue(y,x));
                _bufferOut->Green(y,x, _bufferIn->Green(y,x));
            }else
            {
            int R = matrix[0] * _bufferIn->Red(y-1,x-1) +
                    matrix[1] * _bufferIn->Red(y-1,x) +
                    matrix[2] * _bufferIn->Red(y-1,x+1) +
                    matrix[3] * _bufferIn->Red(y,x-1)+
                    matrix[4] * _bufferIn->Red(y,x) +
                    matrix[5] * _bufferIn->Red(y,x+1) +
                    matrix[6] * _bufferIn->Red(y+1,x-1) +
                    matrix[7] * _bufferIn->Red(y+1,x) +
                    matrix[8] * _bufferIn->Red(y+1,x+1);
            int fR = R / coeff ;
            _bufferOut->Red(y,x,fR);

            int B = matrix[0] * _bufferIn->Blue(y-1,x-1) +
                    matrix[1] * _bufferIn->Blue(y-1,x) +
                    matrix[2] * _bufferIn->Blue(y-1,x+1) +
                    matrix[3] * _bufferIn->Blue(y,x-1)+
                    matrix[4] * _bufferIn->Blue(y,x) +
                    matrix[5] * _bufferIn->Blue(y,x+1) +
                    matrix[6] * _bufferIn->Blue(y+1,x-1) +
                    matrix[7] * _bufferIn->Blue(y+1,x) +
                    matrix[8] * _bufferIn->Blue(y+1,x+1);
            int fB = B / coeff ;
            _bufferOut->Blue(y,x,fB);



           int G =  matrix[0] * _bufferIn->Green(y-1,x-1) +
                    matrix[1] * _bufferIn->Green(y-1,x) +
                    matrix[2] * _bufferIn->Green(y-1,x+1) +
                    matrix[3] * _bufferIn->Green(y,x-1)+
                    matrix[4] * _bufferIn->Green(y,x) +
                    matrix[5] * _bufferIn->Green(y,x+1) +
                    matrix[6] * _bufferIn->Green(y+1,x-1) +
                    matrix[7] * _bufferIn->Green(y+1,x) +
                    matrix[8] * _bufferIn->Green(y+1,x+1);
           int fG = G / coeff ;
           _bufferOut->Green(y,x,fG);


            }
        }

}



ConvFilter::~ConvFilter() {
    delete matrix;
}
