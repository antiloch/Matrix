#include "../s21_matrix.h"
#include <stdlib.h>
#include <math.h>

int s21_transpose(matrix_t *A, matrix_t *result) {
    int flag = OK;
    if (s21_empty_matrix(A) == 1) {
        result = s21_create_matrix(A -> columns, A -> rows, result);
        for (int i = 0; i < A -> rows; i++) {
            for (int j = 0; j < A -> columns; j++) {
                result -> matrix[i][j] == A -> matrix[j][i];
            }
        }
    } else {
        flag = ERROR_MATRIX;
    }
    return flag;
}