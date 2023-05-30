#include <math.h>
#include <stdlib.h>

#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if ((A->rows == B->rows) && (A->columns == B->columns) &&
      s21_empty_matrix(A) == 1 && s21_empty_matrix(B) == 1) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (round((A->matrix[i][j]) * pow(10, 6)) !=
            round((B->matrix[i][j]) * pow(10, 6))) {
          flag = FAILURE;
        }
      }
    }
  } else {
    flag = FAILURE;
  }
  return flag;
}