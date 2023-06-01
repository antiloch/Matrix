#include <check.h>

#include "../s21_matrix.h"
#include "s21_tests.h"

// проверка успешной суммы
START_TEST(sum_0) {
  matrix_t A, B, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 5;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 3;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -2;
  B.matrix[0][2] = -3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 14.01;
  B.matrix[1][2] = -1;
  B.matrix[2][0] = -7;
  B.matrix[2][1] = -18;
  B.matrix[2][2] = 17;

  check.matrix[0][0] = 10;
  check.matrix[0][1] = -3;
  check.matrix[0][2] = 2;
  check.matrix[1][0] = 5;
  check.matrix[1][1] = 17.01;
  check.matrix[1][2] = 3;
  check.matrix[2][0] = -6;
  check.matrix[2][1] = -18;
  check.matrix[2][2] = 20;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// проверка ошибки матрицы
START_TEST(sum_1) {
  matrix_t A, B, result;
  s21_create_matrix(-2, -2, &A);
  s21_create_matrix(2, 2, &B);

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = -3;
  B.matrix[1][1] = 3;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), ERROR_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&result);
}

// проверка ошибки вычислений
START_TEST(sum_2) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(2, 2, &result);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 3;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -2;
  B.matrix[0][2] = -3;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 14;
  B.matrix[1][2] = -1;
  B.matrix[2][0] = -7;
  B.matrix[2][1] = -18;
  B.matrix[2][2] = 17;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

Suite *suite_sum_matrix(void) {
  Suite *s = suite_create("suite_sum_matrix");
  TCase *tc = tcase_create("case_sum_matrix");

  tcase_add_test(tc, sum_0);
  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);

  suite_add_tcase(s, tc);
  return s;
}