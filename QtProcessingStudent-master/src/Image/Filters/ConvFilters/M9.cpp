#include "M9.h"

M9::M9() {
    filterName = "M9";
    coeff = 1;
    int matrix[][3] = {{-1, -1, 0},
                       {-1, 0, 1},
                       {0, 1, 1}};
    setMatrix(matrix);
}

