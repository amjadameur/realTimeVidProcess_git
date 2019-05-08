#include "M2.h"

M2::M2() : ConvFilter() {
    coeff = 1;
    int matrix[][3] = {{-1, 0, 1},
                       {-2, 0, 2},
                       {-1, 0, 1}};
    setMatrix(matrix);
}

