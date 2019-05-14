#include "B2.h"

B2::B2() {
    filterName = "B2";
    coeff = 9;
    int matrix[][3] = {{1, 1, 1},
                       {1, 1, 1},
                       {1, 1, 1}};
    setMatrix(matrix);
}


