#include "M8.h"

M8::M8() {
    filterName = "M8";
    coeff = 1;
    int matrix[][3] = {{-1, -2, -1},
                       {-2, 12, -2},
                       {-1, -2, -1}};
    setMatrix(matrix);
}

