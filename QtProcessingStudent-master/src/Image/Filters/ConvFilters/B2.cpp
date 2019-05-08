#include "B2.h"

B2::B2() : ConvFilter() {
    coeff = 9;
    int matrix[][3] = {{1, 1, 1},
                       {1, 1, 1},
                       {1, 1, 1}};
    setMatrix(matrix);
}


