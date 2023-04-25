#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_atan_0) {
  for (double i = -2; i < 2; i += 0.01) {  // От 0.999940 и до 1.000600
    // начинаются приколы с расхождением
    // да поможет нам бог
    long double res_s21 = s21_atan(i);
    long double res_std = atan(i);
    ck_assert_ldouble_lt(s21_fabs(res_s21 - res_std), 1e-6);
    // _tol почему-то не хочет нормально толерантить
  }
}
END_TEST

START_TEST(test_s21_atan_1) {
  long double arr[] = {14.96, -25.1235, 0.23464, 0, 1, -1};
  for (int i = 0; i < 6; i++)
    ck_assert_double_eq_tol(s21_atan(arr[i]), atan(arr[i]), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_2) {
  // ck_assert_double_eq(s21_atan(INFINITY), atan(INFINITY));
  ck_assert_double_eq_tol(s21_atan(INFINITY), atan(INFINITY), 0.000001);
}
END_TEST

START_TEST(test_s21_atan_3) {
  ck_assert_double_nan(s21_atan(NAN));
  ck_assert_double_nan(atan(NAN));
}
END_TEST

START_TEST(test_s21_atan_4) {
  // ck_assert_double_eq(s21_atan(-INFINITY), atan(-INFINITY));
  ck_assert_double_eq_tol(s21_atan(-INFINITY), atan(-INFINITY), 0.000001);
}
END_TEST

Suite* suite_s21_atan(void) {
  Suite* suite = suite_create("s21_atan");
  TCase* tcase = tcase_create("case_atan");

  tcase_add_test(tcase, test_s21_atan_0);
  tcase_add_test(tcase, test_s21_atan_1);
  tcase_add_test(tcase, test_s21_atan_2);
  tcase_add_test(tcase, test_s21_atan_3);
  tcase_add_test(tcase, test_s21_atan_4);

  suite_add_tcase(suite, tcase);
  return suite;
}
