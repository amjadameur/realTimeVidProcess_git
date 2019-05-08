#include "M3.h"

M3::M3() : ConvFilter() {
    coeff = 1;
    int matrix[][3] = {{-1, 0, 1},
                       {-1, 0, 1},
                       {-1, 0, 1}};
    setMatrix(matrix);
}

