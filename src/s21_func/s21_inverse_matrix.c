#include "../s21_matrix.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int flag = ERROR_CALC;
    // матрица А не пустая
    if (s21_empty_matrix(A) == 1) {
        // случай единичной матрицы
        if (A -> rows == 1) {
            s21_create_matrix(A -> rows, A -> columns, result);
            // минор единичной матрицы - 1
            result -> matrix[0][0] = 1.0 / A -> matrix[0][0];
        } else {
            // детерминант не 0
            if (s21_get_det(A) != 0) {
                s21_create_matrix(A -> rows, A -> columns, result);
                // получаем значение детерминанта 1/|A|
                double det = 1 / s21_get_det(A);
                // строим матрицу алгебраических дополнений для А
                matrix_t calc_matrix;
                flag = s21_calc_complements(A, &calc_matrix);
                // проверяем, что действие успешно
                 if (flag == OK) {
                    // транспонируем матрицу алгебраических дополнений
                    matrix_t trans_matrix;
                    flag = s21_transpose(&calc_matrix, &trans_matrix);
                    if (flag == OK) {
                    // умножаем трансп. матрицу алг. дополнений на обратный детерминант
                        s21_mult_number(&trans_matrix, det, result);
                    }
                    // // очищаем все созданные ранее матрицы
                    s21_remove_matrix(&trans_matrix);
                }
                s21_remove_matrix(&calc_matrix);
            }
        }
    } else {
        flag = ERROR_MATRIX;
    }
    return flag;
}