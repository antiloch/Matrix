#include <check.h>

#include "../s21_matrix.h"
#include "s21_tests.h"

// проверка нахождения матрицы алг дополнений
START_TEST(calc_0) {
  matrix_t A, check, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

// проверка ошибки матрицы
START_TEST(calc_1) {
  matrix_t A, result;

  s21_create_matrix(-3, -3, &A);

  ck_assert_int_eq(s21_calc_complements(&A, &result), ERROR_MATRIX);
  s21_remove_matrix(&A);
}

// проверка ошибки вычислений
START_TEST(calc_2) {
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

  ck_assert_int_eq(s21_calc_complements(&A, &result), ERROR_CALC);
  s21_remove_matrix(&A);
}

Suite *suite_calc_complements(void) {
  Suite *s = suite_create("suite_calc_complements");
  TCase *tc = tcase_create("case_calc_complements");

  tcase_add_test(tc, calc_0);
  tcase_add_test(tc, calc_1);
  tcase_add_test(tc, calc_2);

  suite_add_tcase(s, tc);
  return s;
}