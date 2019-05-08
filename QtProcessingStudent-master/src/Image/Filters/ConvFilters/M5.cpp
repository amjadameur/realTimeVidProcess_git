#include "M5.h"

M5::M5() : ConvFilter() {
    coeff = 1;
    int matrix[][3] = {{-1, -1, -1},
                       {0, 0, 0},
                       {1, 1, 1}};
    setMatrix(matrix);
}

