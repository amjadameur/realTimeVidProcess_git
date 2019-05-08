#include "M4.h"

M4::M4() : ConvFilter() {
    coeff = 1;
    int matrix[][3] = {{-1, -2, -1},
                       {0, 0, 0},
                       {1, 2, 1}};
    setMatrix(matrix);
}

