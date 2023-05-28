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
  tcase_add_test(tc, inverse_1);
  tcase_add_test(tc, inverse_2);

  suite_add_tcase(s, tc);
  return s;
}