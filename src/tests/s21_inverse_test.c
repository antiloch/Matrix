#include <check.h>

#include "../s21_matrix.h"
#include "s21_tests.h"

// проверка нахождения обратной матрицы
START_TEST(inverse_0) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;
  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;
  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// проверка единичной матрицы
START_TEST(inverse_0_1) {
  matrix_t A, result;

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

//сложная обратная матрица
START_TEST(inverse_0_2) {
    matrix_t A, check, result;
    s21_create_matrix(4, 4, &A);
    s21_create_matrix(4, 4, &check);

    A.matrix[0][0] = 6;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 2.03;
    A.matrix[0][3] = 9.99;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = -3;
    A.matrix[1][2] = -90;
    A.matrix[1][3] = 7;
    A.matrix[2][0] = 12;
    A.matrix[2][1] = -6;
    A.matrix[2][2] = 2.25;
    A.matrix[2][3] = 13.098;
    A.matrix[3][0] = -1;
    A.matrix[3][1] = 0;
    A.matrix[3][2] = 24.242424;
    A.matrix[3][3] = -18;

    check.matrix[0][0] = 0.13;
    check.matrix[0][1] = 0.031;
    check.matrix[0][2] = 0.026;
    check.matrix[0][3] = 0.1;
    check.matrix[1][0] = 0.21;
    check.matrix[1][1] = 0.015;
    check.matrix[1][2] = -0.1;
    check.matrix[1][3] = 0.049;
    check.matrix[2][0] = -0.00696;
    check.matrix[2][1] = -0.013;
    check.matrix[2][2] = 0.00405;
    check.matrix[2][3] = -0.00587;
    check.matrix[3][0] = -0.016;
    check.matrix[3][1] = -0.019;
    check.matrix[3][2] = 0.00399;
    check.matrix[3][3] = -0.069;
    
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
}
END_TEST

// проверка ошибки матрицы
START_TEST(inverse_1) {
  matrix_t A, result;

  s21_create_matrix(-3, -3, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), ERROR_MATRIX);
  s21_remove_matrix(&A);
}

// проверка ошибки вычислений
START_TEST(inverse_2) {
  matrix_t A, result;
  s21_create_matrix(3, 4, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 17;
  A.matrix[0][2] = -2;
  A.matrix[0][3] = 9;
  A.matrix[1][0] = 3.06;
  A.matrix[1][1] = 11;
  A.matrix[1][2] = -2.09008;
  A.matrix[1][3] = 20.98;
  A.matrix[2][0] = -0.6;
  A.matrix[2][1] = 60;
  A.matrix[2][2] = -3;
  A.matrix[2][3] = 33;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), ERROR_CALC);
  s21_remove_matrix(&A);
}

Suite *suite_inverse_matrix(void) {
  Suite *s = suite_create("suite_inverse_matrix");
  TCase *tc = tcase_create("case_inverse_matrix");

  tcase_add_test(tc, inverse_0);
  tcase_add_test(tc, inverse_0_1);
  tcase_add_test(tc, inverse_0_2);
  tcase_add_test(tc, inverse_1);
  tcase_add_test(tc, inverse_2);

  suite_add_tcase(s, tc);
  return s;
}