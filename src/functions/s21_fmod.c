#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  short sign = (x < 0) ? -1 : 1;
  long double res;
  y = s21_fabs(y);
  x = s21_fabs(x);
  if (x != s21_INF && x != -s21_INF && (y == s21_INF || y == -s21_INF)) {
    res = x;
  } else if (s21_ISNAN(x) || s21_ISNAN(y) || y == 0 || s21_ISINF(x)) {
    res = s21_NAN;
  } else {
    long double q = (x / y);
    res = x - y * ((long long int)q);
  }
  return res * sign;
}