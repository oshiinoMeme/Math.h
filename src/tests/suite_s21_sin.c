#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_sin_0) {
  ck_assert_double_eq_tol(s21_sin(1530000), sin(1530000), 1e-6);
}
END_TEST

START_TEST(test_s21_sin_1) {
  ck_assert_double_eq_tol(s21_sin(-23.56), sin(-23.56), 1e-6);
}
END_TEST

START_TEST(test_s21_sin_2) {
  ck_assert_double_nan(s21_sin(INFINITY));
  ck_assert_double_nan(sin(INFINITY));
}
END_TEST

START_TEST(test_s21_sin_3) {
  ck_assert_double_nan(s21_sin(NAN));
  ck_assert_double_nan(sin(NAN));
}
END_TEST

START_TEST(test_s21_sin_4) {
  ck_assert_double_nan(s21_sin(-INFINITY));
  ck_assert_double_nan(sin(-INFINITY));
}
END_TEST

START_TEST(test_s21_sin_5) {
  ck_assert_double_eq_tol(s21_sin(0), sin(0), 1e-6);
}
END_TEST

START_TEST(test_s21_sin_6) {
  ck_assert_double_eq_tol(s21_sin(s21_PI * 2), sin(s21_PI * 2), 1e-6);
}
END_TEST

START_TEST(test_s21_sin_7) {
  ck_assert_double_eq_tol(s21_sin(-s21_PI * 2), sin(-s21_PI * 2), 1e-6);
}
END_TEST

Suite *suite_s21_sin(void) {
  Suite *suite = suite_create("s21_sin");
  TCase *tcase = tcase_create("case_s21_sin");

  tcase_add_test(tcase, test_s21_sin_0);
  tcase_add_test(tcase, test_s21_sin_1);
  tcase_add_test(tcase, test_s21_sin_2);
  tcase_add_test(tcase, test_s21_sin_3);
  tcase_add_test(tcase, test_s21_sin_4);
  tcase_add_test(tcase, test_s21_sin_5);
  tcase_add_test(tcase, test_s21_sin_6);
  tcase_add_test(tcase, test_s21_sin_7);

  suite_add_tcase(suite, tcase);

  return suite;
}