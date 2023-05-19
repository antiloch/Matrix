#include "../s21_matrix.h"
#include <stdlib.h>
#include <math.h>

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    if (s21_empty_matrix(A) == 1 && s21_empty_matrix(B) == 1) {
        if (A -> columns == B -> rows) {
            // нужно ли как-то по другому переменную назвать?
            result = s21_create_matrix(A -> rows, B -> columns, result);
            for (int i = 0; i < A -> rows; i++) {
                for (int j = 0; j < B -> columns; j++) {
                    for (int k = 0; k < A -> columns; k++) {
                        result -> matrix[i][j] +=  A -> matrix[i][k] * B -> matrix[k][j];
                    }
                }
            }
        } else {
            flag = ERROR_CALC;
        }
    } else {
        flag = ERROR_MATRIX;
    }
    return flag;
}