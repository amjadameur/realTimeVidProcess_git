#include "M6.h"

M6::M6() : ConvFilter() {
    coeff = 1;
    int matrix[][3] = {{0, -1, 0},
                       {-1, 4, -1},
                       {0, -1, 0}};
    setMatrix(matrix);
}

