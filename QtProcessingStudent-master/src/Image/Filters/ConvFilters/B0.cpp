#include "B0.h"

B0::B0() : ConvFilter() {
    coeff = 8;
    int matrix[][3] = {{0, 1, 0},
                       {1, 4, 1},
                       {0, 1, 0}};
    setMatrix(matrix);
}

