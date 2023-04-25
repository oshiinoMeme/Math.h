#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_tan_0) {
  ck_assert_double_eq_tol(s21_tan(1530000), tan(1530000), 1e-6);
}
END_TEST

START_TEST(test_s21_tan_1) {
  ck_assert_double_eq_tol(s21_tan(-17.56), tan(-17.56), 1e-6);
}
END_TEST

START_TEST(test_s21_tan_2) {
  ck_assert_double_nan(s21_tan(INFINITY));
  ck_assert_double_nan(tan(INFINITY));
}
END_TEST

START_TEST(test_s21_tan_3) {
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_nan(tan(NAN));
}
END_TEST

START_TEST(test_s21_tan_4) {
  ck_assert_double_nan(s21_tan(-INFINITY));
  ck_assert_double_nan(tan(-INFINITY));
}
END_TEST

START_TEST(test_s21_tan_5) {
  ck_assert_double_eq_tol(s21_tan(0), tan(0), 1e-6);
}
END_TEST

START_TEST(test_s21_tan_6) {
  ck_assert_double_eq_tol(s21_tan(s21_PI * 2), tan(s21_PI * 2), 1e-6);
}
END_TEST

START_TEST(test_s21_tan_7) {
  ck_assert_double_eq_tol(s21_tan(-s21_PI * 2), tan(-s21_PI * 2), 1e-6);
}
END_TEST

START_TEST(test_s21_tan_8) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 2), tan(s21_PI / 2), 1e-6);
}
END_TEST

START_TEST(test_s21_tan_9) {
  ck_assert_double_eq_tol(s21_tan(-s21_PI / 2), tan(-s21_PI / 2), 1e-6);
}
END_TEST

Suite *suite_s21_tan(void) {
  Suite *suite = suite_create("s21_tan");
  TCase *tcase = tcase_create("case_s21_tan");

  tcase_add_test(tcase, test_s21_tan_0);
  tcase_add_test(tcase, test_s21_tan_1);
  tcase_add_test(tcase, test_s21_tan_2);
  tcase_add_test(tcase, test_s21_tan_3);
  tcase_add_test(tcase, test_s21_tan_4);
  tcase_add_test(tcase, test_s21_tan_5);
  tcase_add_test(tcase, test_s21_tan_6);
  tcase_add_test(tcase, test_s21_tan_7);
  tcase_add_test(tcase, test_s21_tan_8);
  tcase_add_test(tcase, test_s21_tan_9);

  suite_add_tcase(suite, tcase);

  return suite;
}