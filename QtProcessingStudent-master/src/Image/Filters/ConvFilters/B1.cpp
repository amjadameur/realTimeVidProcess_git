#include "B1.h"

B1::B1() {
    filterName = "B1";
    coeff = 16;
    int matrix[][3] = {{1, 2, 1},
                       {2, 8, 2},
                       {1, 2, 1}};
    setMatrix(matrix);
}

