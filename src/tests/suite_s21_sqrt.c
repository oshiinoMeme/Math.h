#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_sqrt_0) {
  double x = 0;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_1) {
  double x = 234512345634532356.123453456544;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_2) {
  double x = -MAX_DOUBLE;
  ck_assert_double_nan(s21_sqrt(x));
  ck_assert_double_nan(sqrt(x));
}
END_TEST

START_TEST(test_s21_sqrt_3) {
  double x = INFINITY;
  ck_assert_double_infinite(s21_sqrt(x));
  ck_assert_double_infinite(sqrt(x));
}
END_TEST

START_TEST(test_s21_sqrt_4) {
  double x = -INFINITY;
  ck_assert_double_nan(s21_sqrt(x));
  ck_assert_double_nan(sqrt(x));
}
END_TEST

START_TEST(test_s21_sqrt_5) {
  double x = NAN;
  ck_assert_double_nan(s21_sqrt(x));
  ck_assert_double_nan(sqrt(x));
}
END_TEST

START_TEST(test_s21_sqrt_6) {
  double x = -NAN;
  ck_assert_double_nan(s21_sqrt(x));
  ck_assert_double_nan(sqrt(x));
}
END_TEST

START_TEST(test_s21_sqrt_7) {
  long double m[10] = {0.33,      12345,     100000, 324,     54.34556,
                       4.6666666, 0.0000001, 32.2,   43334.5, 0.2};
  for (int i = 0; i < 10; i++) {
    ck_assert_double_eq_tol(s21_sqrt(m[i]), sqrt(m[i]), 1e-6);
  }
}
END_TEST

Suite *suite_s21_sqrt(void) {
  Suite *suite = suite_create("s21_sqrt");
  TCase *tcase = tcase_create("case_s21_sqrt");

  tcase_add_test(tcase, test_s21_sqrt_0);
  tcase_add_test(tcase, test_s21_sqrt_1);
  tcase_add_test(tcase, test_s21_sqrt_2);
  tcase_add_test(tcase, test_s21_sqrt_3);
  tcase_add_test(tcase, test_s21_sqrt_4);
  tcase_add_test(tcase, test_s21_sqrt_5);
  tcase_add_test(tcase, test_s21_sqrt_6);
  tcase_add_test(tcase, test_s21_sqrt_7);

  suite_add_tcase(suite, tcase);

  return suite;
}