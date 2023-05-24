#include "s21_tests.h"
#include <stdio.h>

int main(void) {
  int failed = 0;
  Suite *s21_matrix_test[] = {
      suite_create_matrix(), suite_sum_matrix(), suite_eq_matrix(),
      suite_sub_matrix(), suite_mult_num(), suite_mult_matrix(),
      suite_transpose(), suite_calc_complements(),
      suite_determinant() };

  for (int i = 0; s21_matrix_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_matrix_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    int fail = srunner_ntests_failed(sr);
    if (fail > 0)
      printf("\033[1;41m FAILED: %d \033[0m\n", fail);
    else
      printf("\033[1;42m NO FAILS \033[0m\n");

    failed += fail;
    fail = 0;
    srunner_free(sr);
  }
  if (failed > 0)
    printf("\n\033[1;41m FAILED: %d \033[0m\n", failed);
  else
    printf("\n\033[1;42m ALL TESTS NO FAILS \033[0m\n");

  return failed == 0 ? 0 : 1;
}
