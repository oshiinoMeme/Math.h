#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(s21_log_1) {
  double num = INFINITY;
  ck_assert_ldouble_eq(s21_log(num), log(num));
}
END_TEST

START_TEST(s21_log_2) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s21_log(num));
  ck_assert_ldouble_nan(log(num));
}
END_TEST

START_TEST(s21_log_3) {
  double num = NAN;
  ck_assert_ldouble_nan(s21_log(num));
  ck_assert_ldouble_nan(log(num));
}
END_TEST

START_TEST(s21_log_4) {
  double num = -NAN;
  ck_assert_ldouble_nan(s21_log(num));
  ck_assert_ldouble_nan(log(num));
}
END_TEST

START_TEST(s21_log_5) {
  double num = 0.1;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_6) {
  double num = 1.;
  ck_assert_ldouble_eq(s21_log(num), log(num));
}
END_TEST

START_TEST(s21_log_7) {
  double num = 1.4;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_8) {
  double num = 1.6;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_9) {
  double num = 1.32781;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_10) {
  double num = 43.578;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_11) {
  double num = 68.123456;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_12) {
  double num = 5.5;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_13) {
  double num = 0.0957239;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_14) {
  double num = 1e-300;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_15) {
  double num = 1e+300;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_16) {
  double num = DBL_MAX;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

START_TEST(s21_log_17) {
  double num = 762185.4;
  ck_assert_ldouble_eq_tol(s21_log(num), log(num), s21_EPS);
}
END_TEST

Suite *suite_s21_log(void) {
  Suite *s = suite_create("s21_log");
  TCase *tc = tcase_create("s21_log_tc");

  tcase_add_test(tc, s21_log_1);
  tcase_add_test(tc, s21_log_2);
  tcase_add_test(tc, s21_log_3);
  tcase_add_test(tc, s21_log_4);
  tcase_add_test(tc, s21_log_5);
  tcase_add_test(tc, s21_log_6);
  tcase_add_test(tc, s21_log_7);
  tcase_add_test(tc, s21_log_8);
  tcase_add_test(tc, s21_log_9);
  tcase_add_test(tc, s21_log_10);
  tcase_add_test(tc, s21_log_11);
  tcase_add_test(tc, s21_log_12);
  tcase_add_test(tc, s21_log_13);
  tcase_add_test(tc, s21_log_14);
  tcase_add_test(tc, s21_log_15);
  tcase_add_test(tc, s21_log_16);
  tcase_add_test(tc, s21_log_17);

  suite_add_tcase(s, tc);
  return s;
}