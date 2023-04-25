#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_acos_0) {
  for (double i = -1; i < 1; i += 0.01) {
    long double res_s21 = s21_acos(i);
    long double res_std = acos(i);
    ck_assert_ldouble_eq_tol(res_s21, res_std, 1e-6);
  }
}
END_TEST

START_TEST(test_s21_acos_1) {
  double x = 1.;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);  // 0.
}

START_TEST(test_s21_acos_2) {
  double x = -1.;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);  // 3.141593
}

START_TEST(test_s21_acos_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);  // 1.570796
}

START_TEST(test_s21_acos_4) {
  ck_assert_double_eq_tol(s21_acos(0), acos(0), 0.000001);
}
END_TEST

START_TEST(test_s21_acos_5) {
  ck_assert_double_eq_tol(s21_acos(-0.369), acos(-0.369), 0.000001);
}
END_TEST

START_TEST(test_s21_acos_6) {
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 0.000001);
}
END_TEST

START_TEST(test_s21_acos_7) {
  ck_assert_double_nan(s21_acos(INFINITY));
  ck_assert_double_nan(acos(INFINITY));
}
END_TEST

START_TEST(test_s21_acos_8) {
  ck_assert_double_nan(s21_acos(NAN));
  ck_assert_double_nan(acos(NAN));
}
END_TEST

START_TEST(test_s21_acos_9) {
  ck_assert_double_nan(s21_acos(-INFINITY));
  ck_assert_double_nan(acos(-INFINITY));
}
END_TEST

START_TEST(test_s21_acos_10) {
  ck_assert_double_nan(s21_acos(16));
  ck_assert_double_nan(acos(16));
}
END_TEST

START_TEST(test_s21_acos_11) {
  ck_assert_double_nan(s21_acos(-16));
  ck_assert_double_nan(acos(-16));
}
END_TEST

START_TEST(test_s21_acos_12) {
  ck_assert_double_eq_tol(s21_acos(1), acos(1), 0.000001);
}
END_TEST

Suite* suite_s21_acos(void) {
  Suite* suite = suite_create("s21_acos");
  TCase* tcase = tcase_create("case_acos");

  tcase_add_test(tcase, test_s21_acos_0);
  tcase_add_test(tcase, test_s21_acos_1);
  tcase_add_test(tcase, test_s21_acos_2);
  tcase_add_test(tcase, test_s21_acos_3);
  tcase_add_test(tcase, test_s21_acos_4);
  tcase_add_test(tcase, test_s21_acos_5);
  tcase_add_test(tcase, test_s21_acos_6);
  tcase_add_test(tcase, test_s21_acos_7);
  tcase_add_test(tcase, test_s21_acos_8);
  tcase_add_test(tcase, test_s21_acos_9);
  tcase_add_test(tcase, test_s21_acos_10);
  tcase_add_test(tcase, test_s21_acos_11);
  tcase_add_test(tcase, test_s21_acos_12);

  suite_add_tcase(suite, tcase);
  return suite;
}
