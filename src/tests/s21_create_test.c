#include "../s21_matrix.h"
#include "s21_tests.h"
#include <check.h>

// проверка успешного создания
START_TEST(create_0) {
    matrix_t result;

    ck_assert_int_eq(s21_create_matrix(3, 3, &result), OK);
    s21_remove_matrix(&result);
}
END_TEST

// проверка ошибки матрицы
START_TEST(create_1) {
    matrix_t result;

    ck_assert_int_eq(s21_create_matrix(0, 0, &result), ERROR_MATRIX);
    //s21_remove_matrix(&result);
}
END_TEST

Suite *suite_create_matrix(void) {
    Suite *s = suite_create("suite_create_matrix");
    TCase *tc = tcase_create("case_create_matrix");

    tcase_add_test(tc, create_0);
    tcase_add_test(tc, create_1);

    suite_add_tcase(s, tc);
    return s;
}