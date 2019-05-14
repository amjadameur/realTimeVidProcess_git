#include "M0.h"

M0::M0() {
    filterName = "M0";
    coeff = 1;
    int matrix[][3] = {{0, 0, 0},
                       {-1, 0, 1},
                       {0, 0, 0}};
    setMatrix(matrix);
}


