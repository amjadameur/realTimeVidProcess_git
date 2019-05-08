#include "B3.h"

B3::B3() : ConvFilter() {
    coeff = 8;
    int matrix[][3] = {{1, 1, 1},
                       {1, 0, 1},
                       {1, 1, 1}};
    setMatrix(matrix);
}

