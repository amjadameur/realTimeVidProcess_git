#include "M7.h"

M7::M7() {
    filterName = "M7";
    coeff = 1;
    int matrix[][3] = {{-1, -1, -1},
                       {-1, 8, -1},
                       {-1, -1, -1}};
    setMatrix(matrix);
}

