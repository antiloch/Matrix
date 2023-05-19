#include "../s21_matrix.h"
#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int flag = OK;
    if  (rows > 0 && columns > 0) {
        result -> rows = rows;
        result -> columns = columns;
        result -> matrix = (double **)calloc(rows, sizeof(double *));
        if (result -> matrix != NULL) {
            for (int i = 0; i < rows; i++) {
                result -> matrix[i] = (double *)calloc(columns, sizeof(double));
            }
        } else {
            flag = ERROR_MATRIX;
        }
    } else {
        flag = ERROR_MATRIX;
    }
    return flag;
}