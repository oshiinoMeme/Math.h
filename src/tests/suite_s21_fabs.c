#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_fabs_0) {
  ck_assert_double_eq(s21_fabs(INFINITY), fabs(INFINITY));
}
END_TEST

START_TEST(test_s21_fabs_1) {
  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_nan(fabs(NAN));
}
END_TEST

START_TEST(test_s21_fabs_2) {
  ck_assert_double_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(test_s21_fabs_3) {
  ck_assert_double_eq_tol(s21_fabs(2134.434), fabs(2134.434), 0.000001);
}
END_TEST

START_TEST(test_s21_fabs_4) {
  ck_assert_double_eq_tol(s21_fabs(-23134.434), fabs(-23134.434), 0.000001);
}
END_TEST

Suite *suite_s21_fabs(void) {
  Suite *suite = suite_create("s21_fabs");
  TCase *tcase = tcase_create("case_s21_fabs");

  tcase_add_test(tcase, test_s21_fabs_0);
  tcase_add_test(tcase, test_s21_fabs_1);
  tcase_add_test(tcase, test_s21_fabs_2);
  tcase_add_test(tcase, test_s21_fabs_3);
  tcase_add_test(tcase, test_s21_fabs_4);

  suite_add_tcase(suite, tcase);

  return suite;
}