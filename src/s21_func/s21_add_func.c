#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "../s21_matrix.h"

// проверка, пустая ли матрица
// 0 - пустая
// 1 - не пустая
int s21_empty_matrix(matrix_t *A) {
  int flag = SUCCESS;
  if (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL || A == NULL) {
    flag = FAILURE;
  } 
  return flag;
}

// вывод матрицы на экран
void s21_print_matrix(matrix_t *A) {
  for (int i = 0; i < A -> rows; i++) {
    for (int j = 0; j < A -> columns; j++) {
      printf("%f%s", A -> matrix[i][j], " ");
    }
    printf("%s", "\n");
  }
  printf("%s", "\n");
}