#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = ERROR_CALC;
  // матрица А не пустая
  if (s21_empty_matrix(A) == 1) {
    // случай единичной матрицы
    if (A->rows == 1 && A->columns == 1) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      // минор единичной матрицы - 1
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    } else {
      if (A->rows == A->columns) {
        // копируем матрицу A в copy, чтобы не изменять значения A
        matrix_t copy;
        s21_copy_matrix(A, &copy);
        double det = s21_get_det(&copy);
        s21_remove_matrix(&copy);
        // детерминант не 0
        if (det != 0) {
          // получаем значение детерминанта 1/|A|
          det = 1 / det;
          // строим матрицу алгебраических дополнений для А
          matrix_t calc_matrix;
          flag = s21_calc_complements(A, &calc_matrix);
          // проверяем, что действие успешно
          if (flag == OK) {
            // транспонируем матрицу алгебраических дополнений
            matrix_t trans_matrix;
            flag = s21_transpose(&calc_matrix, &trans_matrix);
            if (flag == OK) {
              // умножаем трансп. матрицу алг. дополнений на обратный
              // детерминант
              s21_mult_number(&trans_matrix, det, result);
            }
            // очищаем все созданные ранее матрицы
            s21_remove_matrix(&trans_matrix);
          }
          s21_remove_matrix(&calc_matrix);
        }
      }
    }
  } else {
    flag = ERROR_MATRIX;
  }
  return flag;
}