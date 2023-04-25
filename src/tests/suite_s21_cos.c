#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_cos_0) {
  ck_assert_double_eq_tol(s21_cos(1530000), cos(1530000), 1e-6);
}
END_TEST

START_TEST(test_s21_cos_1) {
  ck_assert_double_eq_tol(s21_cos(-23.56), cos(-23.56), 1e-6);
}
END_TEST

START_TEST(test_s21_cos_2) {
  ck_assert_double_nan(s21_cos(INFINITY));
  ck_assert_double_nan(cos(INFINITY));
}
END_TEST

START_TEST(test_s21_cos_3) {
  ck_assert_double_nan(s21_cos(NAN));
  ck_assert_double_nan(cos(NAN));
}
END_TEST

START_TEST(test_s21_cos_4) {
  ck_assert_double_nan(s21_cos(-INFINITY));
  ck_assert_double_nan(cos(-INFINITY));
}
END_TEST

START_TEST(test_s21_cos_5) {
  ck_assert_double_eq_tol(s21_cos(0), cos(0), 1e-6);
}
END_TEST

START_TEST(test_s21_cos_6) {
  ck_assert_double_eq_tol(s21_cos(s21_PI * 2), cos(s21_PI * 2), 1e-6);
}
END_TEST

START_TEST(test_s21_cos_7) {
  ck_assert_double_eq_tol(s21_cos(-s21_PI * 2), cos(-s21_PI * 2), 1e-6);
}
END_TEST

Suite *suite_s21_cos(void) {
  Suite *suite = suite_create("s21_cos");
  TCase *tcase = tcase_create("case_s21_cos");

  tcase_add_test(tcase, test_s21_cos_0);
  tcase_add_test(tcase, test_s21_cos_1);
  tcase_add_test(tcase, test_s21_cos_2);
  tcase_add_test(tcase, test_s21_cos_3);
  tcase_add_test(tcase, test_s21_cos_4);
  tcase_add_test(tcase, test_s21_cos_5);
  tcase_add_test(tcase, test_s21_cos_6);
  tcase_add_test(tcase, test_s21_cos_7);

  suite_add_tcase(suite, tcase);

  return suite;
}