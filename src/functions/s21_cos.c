#include "../s21_math.h"

long double s21_cos(double x) {
  short sign = -1;
  long double res = 1;
  x = s21_fmod(x, 2 * s21_PI);
  for (int i = 2; i < 30; i += 2) {
    res += sign * (s21_pow(x, i) / factor(i));
    sign *= -1;
  }
  return res;
}