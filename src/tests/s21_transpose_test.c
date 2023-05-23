#include "../s21_matrix.h"
#include "s21_tests.h"
#include <check.h>

// проверка успешного транспонирования
START_TEST(transpose_0) {
    matrix_t A, result;
    s21_create_matrix(2, 3, &A);

    A.matrix[0][0] = 6;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 2.03;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = -3;
    A.matrix[1][2] = -90;
    
    ck_assert_int_eq(s21_transpose(&A, &result), OK);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
}
END_TEST

// проверка ошибки матрицы
START_TEST(transpose_1) {
    matrix_t A, result;
    s21_create_matrix(3, 4, &A);
    
    A.matrix = NULL;

    ck_assert_int_eq(s21_transpose(&A, &result), ERROR_MATRIX);
    s21_remove_matrix(&A);
    //s21_remove_matrix(&result);
}

Suite *suite_transpose(void) {
    Suite *s = suite_create("suite_transpose");
    TCase *tc = tcase_create("case_transpose");

    tcase_add_test(tc, transpose_0);
    tcase_add_test(tc, transpose_1);

    suite_add_tcase(s, tc);
    return s;
}