#include "M1.h"

M1::M1() {
    filterName = "M1";
    coeff = 1;
    int matrix[][3] = {{0, 0, 0},
                       {-1, 2, -1},
                       {0, 0, 0}};
    setMatrix(matrix);
}

