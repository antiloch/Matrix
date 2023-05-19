#include "../s21_matrix.h"
#include <stdlib.h>
#include <math.h>

int s21_determinant(matrix_t *A, double *result) {
    int flag = OK;
    double det = 0.0;
    if (s21_empty_matrix(A) == 1) {
        if (A -> rows == A -> columns) {
            result = s21_create_matrix(A -> rows, A -> columns, result);
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
    if (A -> rows == 1 && A -> columns == 1) {
            det = A -> matrix[0][0];
    } else {
        // приведение матрицы к треугольному виду методом Гаусса
        for (int i = 0; i < A -> columns; i++) {
            for (int j = 0; j < A -> rows; j++) {
                // проверяем условие, что элемент ниже главной диагонали
                if ((i + j) < (i * 2)) {
                    if (A -> matrix[i][j] != 0) {
                        // коэффициент, на который будем умножать строку
                        // т.к. арифм операции совершаем только с первой строкой, значение i фиксировано 0
                        double coef = A -> matrix[i][j] / A -> matrix[0][j];
                        // умножаем первую строку на коэффициент
                        for (int k = 0; k < A -> columns; k++) {
                            A -> matrix[0][k] = A -> matrix[0][k] * coef;
                            // вычитаем из строки строку с коэффициентом
                            A -> matrix[i][k] -= A -> matrix[0][k];
                        }
                    }
                }
            }
        }
        // определитель матрицы второго и порядков выше
        det = 1.0;
        for (int m = 0; m < A -> rows; m++) {
            det *= A -> matrix[m][m];
        }
    }
    return det;
}