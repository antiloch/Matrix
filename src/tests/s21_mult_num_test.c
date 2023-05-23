#include "../s21_matrix.h"
#include "s21_tests.h"
#include <check.h>

// проверка успешного умножения
START_TEST(mult_num_0) {
    matrix_t A, result;
    s21_create_matrix(3, 3, &A);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = -1;
    A.matrix[0][2] = 5;
    A.matrix[1][0] = 2;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 0;
    A.matrix[2][2] = 3;

    ck_assert_int_eq(s21_mult_number(&A, 90.05, &result), OK);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
}
END_TEST

// проверка ошибки матрицы
START_TEST(mult_num_1) {
    matrix_t A, result;
    s21_create_matrix(2, 2, &A);
    
    A.matrix = NULL;

    ck_assert_int_eq(s21_mult_number(&A, 4.000001, &result), ERROR_MATRIX);
    s21_remove_matrix(&A);
    //s21_remove_matrix(&result);
}


Suite *suite_mult_num(void) {
    Suite *s = suite_create("suite_mult_num");
    TCase *tc = tcase_create("case_mult_num");

    tcase_add_test(tc, mult_num_0);
    tcase_add_test(tc, mult_num_1);

    suite_add_tcase(s, tc);
    return s;
}