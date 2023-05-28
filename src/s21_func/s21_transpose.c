#include <math.h>
#include <stdlib.h>

#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = ERROR_MATRIX;
  if (s21_empty_matrix(A) == 1) {
    flag = s21_create_matrix(A->columns, A->rows, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }
  return flag;
}