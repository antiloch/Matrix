#include "../s21_matrix.h"
#include <stdlib.h>
#include <math.h>

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    if (s21_empty_matrix(A) == 1 && s21_empty_matrix(B) == 1) {
        if ((A -> rows == B -> rows) && (A -> columns == B -> columns)) {
            // нужно ли как-то по другому переменную назвать?
            flag = s21_create_matrix(A -> rows, A -> columns, result);
            for (int i = 0; i < A -> rows; i++) {
                for (int j = 0; j < A -> columns; j++) {
                    result -> matrix[i][j] = A -> matrix[i][j] - B -> matrix[i][j];
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