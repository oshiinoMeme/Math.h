#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_asin_0) {
  for (double i = -1; i < 1; i += 0.01) {
    long double res_s21 = s21_asin(i);
    long double res_std = asin(i);
    ck_assert_ldouble_eq_tol(res_s21, res_std, 1e-6);
  }
}
END_TEST

START_TEST(test_s21_asin_1) {
  double x = 1.;
  ck_assert_double_eq_tol(s21_asin(x), 1.570796, 1e-6);
}

START_TEST(test_s21_asin_2) {
  double x = -1.;
  ck_assert_double_eq_tol(s21_asin(x), -1.570796, 1e-6);
}

START_TEST(test_s21_asin_3) {
  double x = 0.;
  ck_assert_double_eq_tol(s21_asin(x), 0., 1e-6);
}

START_TEST(test_s21_asin_4) {
  ck_assert_double_eq_tol(s21_asin(0.156), asin(0.156), 0.000001);
}
END_TEST

START_TEST(test_s21_asin_5) {
  ck_assert_double_eq_tol(s21_asin(1), asin(1), 0.000001);
}
END_TEST

START_TEST(test_s21_asin_6) {
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), 0.000001);
}
END_TEST

START_TEST(test_s21_asin_7) {
  ck_assert_double_nan(s21_asin(INFINITY));
  ck_assert_double_nan(asin(INFINITY));
}
END_TEST

START_TEST(test_s21_asin_8) {
  ck_assert_double_nan(s21_asin(NAN));
  ck_assert_double_nan(asin(NAN));
}
END_TEST

START_TEST(test_s21_asin_9) {
  ck_assert_double_nan(s21_asin(-INFINITY));
  ck_assert_double_nan(asin(-INFINITY));
}
END_TEST

START_TEST(test_s21_asin_10) {
  ck_assert_double_nan(s21_asin(16));
  ck_assert_double_nan(asin(16));
}
END_TEST

START_TEST(test_s21_asin_11) {
  ck_assert_double_nan(s21_asin(-16));
  ck_assert_double_nan(asin(-16));
}
END_TEST

START_TEST(test_s21_asin_12) {
  ck_assert_double_eq_tol(s21_asin(0), asin(0), 0.000001);
}
END_TEST

Suite* suite_s21_asin(void) {
  Suite* suite = suite_create("s21_asin");
  TCase* tcase = tcase_create("case_asin");

  tcase_add_test(tcase, test_s21_asin_0);
  tcase_add_test(tcase, test_s21_asin_1);
  tcase_add_test(tcase, test_s21_asin_2);
  tcase_add_test(tcase, test_s21_asin_3);
  tcase_add_test(tcase, test_s21_asin_4);
  tcase_add_test(tcase, test_s21_asin_5);
  tcase_add_test(tcase, test_s21_asin_6);
  tcase_add_test(tcase, test_s21_asin_7);
  tcase_add_test(tcase, test_s21_asin_8);
  tcase_add_test(tcase, test_s21_asin_9);
  tcase_add_test(tcase, test_s21_asin_10);
  tcase_add_test(tcase, test_s21_asin_11);
  tcase_add_test(tcase, test_s21_asin_12);

  suite_add_tcase(suite, tcase);
  return suite;
}
