#include "../s21_math.h"

long double s21_asin(double x) {
  long double result = 0;
  if (isEqual(x, -1.))
    result = -1.570796;
  else if (isEqual(x, 1.))
    result = 1.570796;
  else if (x > 1. || x < -1. || s21_ISNAN(x))
    result = s21_NAN;
  else if (s21_fabs(x) < 1.) {
    x = x / s21_sqrt(1 - x * x);
    result = s21_atan(x);
  }
  return result;
}