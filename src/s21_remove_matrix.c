#include "s21_matrix.h"
#include <stdlib.h>

void s21_remove_matrix(matrix_t *A) {
    if (A -> matrix != NULL) {
        for (int i = 0; i < A -> rows; i++) {
            free(A -> matrix[i]);
        }
        free(A -> matrix);
    }
    A -> rows = 0;
    A -> columns = 0;
    A -> matrix = NULL;
}