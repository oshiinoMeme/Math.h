#include "../s21_math.h"
#include "../suitecases.h"

START_TEST(test_s21_fmod_0) {
  long double x[15] = {123,           3234.54,         -213,          543.,
                       543.12453,     4555532352.543,  -451.11,       2.2,
                       0.0,           3.333333,        -0.123333,     0.44444,
                       0.00000000342, -0.000003424234, -4234.23412434};
  long double y[15] = {432.234,    1,      0.021,     432,      53,
                       324.000001, 4342,   54,        5.,       333.,
                       3.3333,     -9.123, -123.4323, 81824883, 23456};
  for (int i = 0; i < 15; i++) {
    ck_assert_double_eq_tol(s21_fmod(x[i], y[i]), fmod(x[i], y[i]), 1e-6);
  }
}
END_TEST

START_TEST(test_s21_fmod_1) {
  ck_assert_double_nan(s21_fmod(NAN, NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(test_s21_fmod_2) {
  ck_assert_double_nan(s21_fmod(-INFINITY, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_3) {
  ck_assert_double_nan(s21_fmod(-INFINITY, INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_4) {
  ck_assert_double_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_5) {
  ck_assert_double_nan(s21_fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(NAN, INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_6) {
  ck_assert_double_nan(s21_fmod(-INFINITY, NAN));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(test_s21_fmod_7) {
  ck_assert_double_eq_tol(s21_fmod(MAX_DOUBLE, MAX_DOUBLE + 1),
                          fmod(MAX_DOUBLE, MAX_DOUBLE + 1), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_8) {
  ck_assert_double_eq_tol(s21_fmod(3, INFINITY), fmod(3, INFINITY), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_9) {
  ck_assert_double_eq_tol(s21_fmod(3, -INFINITY), fmod(3, -INFINITY), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_10) {
  ck_assert_double_nan(s21_fmod(INFINITY, NAN));
  ck_assert_double_nan(fmod(INFINITY, NAN));
}
END_TEST

START_TEST(test_s21_fmod_11) {
  ck_assert_double_nan(s21_fmod(INFINITY, -INFINITY));
  ck_assert_double_nan(fmod(INFINITY, -INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_12) {
  ck_assert_double_nan(s21_fmod(INFINITY, 3));
  ck_assert_double_nan(fmod(INFINITY, 3));
}
END_TEST

START_TEST(test_s21_fmod_13) {
  ck_assert_double_nan(s21_fmod(-INFINITY, 2));
  ck_assert_double_nan(fmod(-INFINITY, 2));
}
END_TEST

START_TEST(test_s21_fmod_14) {
  ck_assert_double_nan(s21_fmod(NAN, 1));
  ck_assert_double_nan(fmod(NAN, 1));
}
END_TEST

START_TEST(test_s21_fmod_15) {
  ck_assert_double_eq(s21_fmod(0, INFINITY), fmod(0, INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_16) {
  ck_assert_double_eq(s21_fmod(0, -INFINITY), fmod(0, -INFINITY));
}
END_TEST

START_TEST(test_s21_fmod_17) {
  ck_assert_double_nan(s21_fmod(0, NAN));
  ck_assert_double_nan(fmod(0, NAN));
}
END_TEST

START_TEST(test_s21_fmod_18) {
  ck_assert_double_nan(s21_fmod(INFINITY, 0));
  ck_assert_double_nan(fmod(INFINITY, 0));
}
END_TEST

START_TEST(test_s21_fmod_19) {
  ck_assert_double_nan(s21_fmod(-INFINITY, 0));
  ck_assert_double_nan(fmod(-INFINITY, 0));
}
END_TEST

START_TEST(test_s21_fmod_20) {
  ck_assert_double_nan(s21_fmod(NAN, 0));
  ck_assert_double_nan(fmod(NAN, 0));
}
END_TEST

START_TEST(test_s21_fmod_21) {
  ck_assert_double_eq_tol(s21_fmod(3, -2), fmod(3, -2), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_22) {
  ck_assert_double_eq_tol(s21_fmod(-3, 2), fmod(-3, 2), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_23) {
  ck_assert_double_nan(s21_fmod(-3, 0));
  ck_assert_double_nan(fmod(-3, 0));
}
END_TEST

START_TEST(test_s21_fmod_24) {
  ck_assert_double_eq_tol(s21_fmod(0, INFINITY), fmod(0, INFINITY), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_25) {
  // ck_assert_double_eq_tol(s21_fmod(0, -INFINITY), fmod(0, -INFINITY), 1e-6);
  // ck_assert_double_eq_tol(s21_fmod(-INFINITY, NAN), fmod(-INFINITY, NAN),
  // 1e-6);
  ck_assert_double_nan(s21_fmod(s21_INF, s21_INF));
  ck_assert_double_nan(fmod(s21_INF, s21_INF));
}
END_TEST

Suite *suite_s21_fmod(void) {
  Suite *suite = suite_create("s21_fmod");
  TCase *tcase = tcase_create("case_s21_fmod");

  tcase_add_test(tcase, test_s21_fmod_0);
  tcase_add_test(tcase, test_s21_fmod_1);
  tcase_add_test(tcase, test_s21_fmod_2);
  tcase_add_test(tcase, test_s21_fmod_3);
  tcase_add_test(tcase, test_s21_fmod_4);
  tcase_add_test(tcase, test_s21_fmod_5);
  tcase_add_test(tcase, test_s21_fmod_6);
  tcase_add_test(tcase, test_s21_fmod_7);
  tcase_add_test(tcase, test_s21_fmod_8);
  tcase_add_test(tcase, test_s21_fmod_9);
  tcase_add_test(tcase, test_s21_fmod_10);
  tcase_add_test(tcase, test_s21_fmod_11);
  tcase_add_test(tcase, test_s21_fmod_12);
  tcase_add_test(tcase, test_s21_fmod_13);
  tcase_add_test(tcase, test_s21_fmod_14);
  tcase_add_test(tcase, test_s21_fmod_15);
  tcase_add_test(tcase, test_s21_fmod_16);
  tcase_add_test(tcase, test_s21_fmod_17);
  tcase_add_test(tcase, test_s21_fmod_18);
  tcase_add_test(tcase, test_s21_fmod_19);
  tcase_add_test(tcase, test_s21_fmod_20);
  tcase_add_test(tcase, test_s21_fmod_21);
  tcase_add_test(tcase, test_s21_fmod_22);
  tcase_add_test(tcase, test_s21_fmod_23);
  tcase_add_test(tcase, test_s21_fmod_24);
  tcase_add_test(tcase, test_s21_fmod_25);

  suite_add_tcase(suite, tcase);

  return suite;
}