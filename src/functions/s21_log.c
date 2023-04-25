#include "../s21_math.h"

long double log_galley(long double x) {
  long double res = x;
  for (int i = 0; i < 200; i++) {
    res = (res + 2 * (x - s21_exp(res)) / (x + s21_exp(res)));
  }
  return res;
}

long double s21_ln(long double x) {
  long double res = 0;
  while (x < 0.5) {
    x *= s21_EXP;
    res--;
  }
  while (x > 1.5) {
    x /= s21_EXP;
    res++;
  }
  res += log_galley(x);
  return res;
}

long double s21_log(double x) {
  long double res = 0;
  if (x != x || x < 0)
    res = s21_NAN;
  else if (x == s21_INF)
    res = s21_INF;
  else if (x == 0)
    res = -s21_INF;
  else if (x != 1)
    res = s21_ln(x);
  return res;
}