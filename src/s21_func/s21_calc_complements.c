#include "../s21_matrix.h"
#include <stdlib.h>
#include <math.h>

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int flag = OK;
    if (s21_empty_matrix(A) == 1) {
        if (A -> rows == A -> columns) {
            s21_create_matrix(A -> rows, A -> columns, result);
            for (int i = 0; i < A -> rows; i++) {
                for (int j = 0; j < A -> columns; j++) {
                    // создаем матрицу минора для каждого элемента
                    matrix_t minor;
                    s21_create_matrix(A -> rows - 1, A -> columns - 1, &minor);
                    s21_minor_matrix(A, &minor, i, j);
                    // создаем переменную для детерминанта минора
                    double det = 0.0;
                    det = s21_get_det(&minor);
                    result -> matrix[i][j] = pow(-1, (i+j)) * det;
                    s21_remove_matrix(&minor);
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

void s21_minor_matrix(matrix_t *A, matrix_t *minor, int r, int c) {
    int minor_r = 0, minor_c = 0;
    for (int i = 0; i < A -> rows; i++) {
        for (int j = 0; j < A -> columns; j++) {
            if (i != r) {
                if (j != c) {
                    minor -> matrix[minor_r][minor_c] = A -> matrix[i][j];
                    minor_c += 1;
                }
                // проверяем что строка в матрице минора дошла до конца
                if (minor_c > (A -> columns - 1)) {
                    minor_c = 0;
                    minor_r += 1;
                }
            }
        }
    }
}
