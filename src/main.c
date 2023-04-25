#include "s21_math.h"
#include "suitecases.h"

void run_testcase(Suite *testcase) {
  SRunner *runner = srunner_create(testcase);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}

void run_all_testcases() {
  Suite *list_cases[] = {
      suite_s21_sqrt(), suite_s21_abs(),  suite_s21_acos(),  suite_s21_asin(),
      suite_s21_atan(), suite_s21_ceil(), suite_s21_floor(), suite_s21_fmod(),
      suite_s21_pow(),  suite_s21_exp(),  suite_s21_cos(),   suite_s21_sin(),
      suite_s21_tan(),  suite_s21_fabs(), suite_s21_log(),   NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main() {
  run_all_testcases();

  return 0;
}