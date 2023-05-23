#include "s21_tests.h"
#include <check.h>
#include "../s21_matrix.h"

// матрицы равны
START_TEST(eq_0) {
    matrix_t A, B;
    s21_create_matrix(2, 3, &A);
    s21_create_matrix(2, 3, &B);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = -1;
    A.matrix[0][2] = 0;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 5;
    A.matrix[1][2] = 2.555555;

    B.matrix[0][0] = 1;
    B.matrix[0][1] = -1;
    B.matrix[0][2] = 0;
    B.matrix[1][0] = 6;
    B.matrix[1][1] = 5;
    B.matrix[1][2] = 2.555555;

    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

// матрицы не равны (размеры)
START_TEST(eq_1) {
    matrix_t A, B;
    s21_create_matrix(2, 2, &A);
    s21_create_matrix(2, 3, &B);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = -1;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 6;

    B.matrix[0][0] = 1;
    B.matrix[0][1] = -1;
    B.matrix[0][2] = 0;
    B.matrix[1][0] = 6;
    B.matrix[1][1] = 5;
    B.matrix[1][2] = 2.555555;

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST

// матрицы не равны (значения)
START_TEST(eq_2) {
    matrix_t A, B;
    s21_create_matrix(2, 3, &A);
    s21_create_matrix(2, 3, &B);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = -1;
    A.matrix[0][2] = 0;
    A.matrix[1][0] = 6.000001;
    A.matrix[1][1] = 5;
    A.matrix[1][2] = 2.555555;

    B.matrix[0][0] = 1;
    B.matrix[0][1] = -1;
    B.matrix[0][2] = 0;
    B.matrix[1][0] = 6;
    B.matrix[1][1] = 5;
    B.matrix[1][2] = 2.555555;

    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
}
END_TEST


Suite *suite_eq_matrix(void) {
    Suite *s = suite_create("suite_eq_matrix");
    TCase *tc = tcase_create("case_eq_matrix");

    tcase_add_test(tc, eq_0);
    tcase_add_test(tc, eq_1);
    tcase_add_test(tc, eq_2);

    suite_add_tcase(s, tc);
    return s;
}