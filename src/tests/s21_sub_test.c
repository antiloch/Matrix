#include <check.h>

#include "../s21_matrix.h"
#include "s21_tests.h"

// проверка успешной разности
START_TEST(sub_0) {
  matrix_t A, B, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = -1.01010101;
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
  B.matrix[1][1] = 14;
  B.matrix[1][2] = -1;
  B.matrix[2][0] = -7;
  B.matrix[2][1] = -18;
  B.matrix[2][2] = 17;

  check.matrix[0][0] = -8;
  check.matrix[0][1] = 0.98989899;
  check.matrix[0][2] = 8;
  check.matrix[1][0] = -1;
  check.matrix[1][1] = -11;
  check.matrix[1][2] = 5;
  check.matrix[2][0] = 8;
  check.matrix[2][1] = 18;
  check.matrix[2][2] = -14;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// проверка ошибки матрицы
START_TEST(sub_1) {
  matrix_t A, B, result;
  s21_create_matrix(-2, -2, &A);
  s21_create_matrix(2, 2, &B);

  B.matrix[0][0] = 9;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = -3;
  B.matrix[1][1] = 3;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), ERROR_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&result);
}

// проверка ошибки вычислений
START_TEST(sub_2) {
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

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

Suite *suite_sub_matrix(void) {
  Suite *s = suite_create("suite_sub_matrix");
  TCase *tc = tcase_create("case_sub_matrix");

  tcase_add_test(tc, sub_0);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);

  suite_add_tcase(s, tc);
  return s;
}