#include "../s21_matrix.h"
#include <stdlib.h>
#include <math.h>

// проверка, пустая ли матрица
// 0 - пустая
// 1 - не пустая
int s21_empty_matrix(matrix_t *A) {
    int flag = SUCCESS;
    if (A -> rows <= 0 || A -> columns <= 0 || 
    A -> matrix == NULL || A == NULL) {
        flag = FAILURE;
    }
    return flag;
}