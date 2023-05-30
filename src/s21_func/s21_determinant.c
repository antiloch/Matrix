#include <math.h>
#include <stdlib.h>

#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (s21_empty_matrix(A) == 1) {
    if (A->rows == A->columns) {
      *result = s21_get_det(A);
    } else {
      flag = ERROR_CALC;
    }
  } else {
    flag = ERROR_MATRIX;
  }
  return flag;
}

double s21_get_det(matrix_t *A) {
  double det = 0.0;
  // детерминант матрицы первого порядка - ее элемент
  if (A->rows == 1 && A->columns == 1) {
    det = A->matrix[0][0];
  } else {
    // приведение матрицы к треугольному виду методом Гаусса
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        // проверяем условие, что элемент ниже главной диагонали
        if ((i + j) < (i * 2)) {
          if (A->matrix[i][j] != 0) {
            // коэффициент, на который будем умножать строку
            // арифм операции совершаем с предыдущей строкой
            double coef = A->matrix[i][j] / A->matrix[j][j];
            // умножаем первую строку на коэффициент
            for (int k = 0; k < A->columns; k++) {
              // вычитаем из строки строку с коэффициентом
              A->matrix[i][k] -= A->matrix[j][k] * coef;
            }
          }
        }
      }
    }
    // определитель матрицы второго и порядков выше
    det = 1.0;
    for (int m = 0; m < A->rows; m++) {
      det *= A->matrix[m][m];
    }
  }
  return det;
}