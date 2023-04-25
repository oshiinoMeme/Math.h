#include "../s21_math.h"

long double s21_exp(double x) {
  long double res = 1.0L;
  long double series = 1.0L;
  long double i = 1.0L;
  int flag = 0;
  int minus = 0;
  if (x < 0) {
    x *= -1;
    minus = 1;
  }
  while (s21_fabs(res) > 1e-17 && !flag) {
    res *= x / i;
    series += res;
    i++;
    if (series > DBL_MAX) {
      series = s21_INF;
      flag = 1;
    }
  }
  if (minus) series = 1.0 / series;
  return series;
}
