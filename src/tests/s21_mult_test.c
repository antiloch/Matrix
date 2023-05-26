#include "../s21_matrix.h"
#include "s21_tests.h"
#include <check.h>

// проверка успешного умножения
START_TEST(mult_0) {
    matrix_t A, B, result;
    s21_create_matrix(2, 3, &A);
    s21_create_matrix(3, 2, &B);

    A.matrix[0][0] = 6;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 0;
    A.matrix[1][0] = 1.01;
    A.matrix[1][1] = -3;
    A.matrix[1][2] = -90.350001;
    
    B.matrix[0][0] = 2;
    B.matrix[0][1] = -33.08;
    B.matrix[1][0] = 12;
    B.matrix[1][1] = 1.01;
    B.matrix[2][0] = 0;
    B.matrix[2][1] = -5.2;

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
}
END_TEST

// проверка ошибки матрицы
START_TEST(mult_1) {
    matrix_t A, B, result;
    s21_create_matrix(-2, -2, &A);
    s21_create_matrix(2, 2, &B);
    
    B.matrix[0][0] = 2.25;
    B.matrix[0][1] = -11.04;
    B.matrix[1][0] = 0.00005;
    B.matrix[1][1] = 16;

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), ERROR_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    //s21_remove_matrix(&result);
}

// проверка ошибки вычислений
START_TEST(mult_2) {
    matrix_t A, B, result;
    s21_create_matrix(2, 3, &A);
    s21_create_matrix(2, 3, &B);

    A.matrix[0][0] = 6;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 0;
    A.matrix[1][0] = 1.01;
    A.matrix[1][1] = -3;
    A.matrix[1][2] = -90.350001;
    
    B.matrix[0][0] = 2;
    B.matrix[0][1] = -33.08;
    B.matrix[0][2] = 12;
    B.matrix[1][0] = 1.01;
    B.matrix[1][1] = 0;
    B.matrix[1][2] = -5.2;

    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), ERROR_CALC);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    //s21_remove_matrix(&result);
}
END_TEST


Suite *suite_mult_matrix(void) {
    Suite *s = suite_create("suite_mult_matrix");
    TCase *tc = tcase_create("case_mult_matrix");

    tcase_add_test(tc, mult_0);
    tcase_add_test(tc, mult_1);
    tcase_add_test(tc, mult_2);

    suite_add_tcase(s, tc);
    return s;
}