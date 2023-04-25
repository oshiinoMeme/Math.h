#include "../s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (isEqual(x, -1.))
    result = 3.141593;
  else if (x > 1. || x <= -1. || s21_ISNAN(x))
    result = s21_NAN;
  else if (isEqual(x, 1.))
    result = 0.;
  else if (isEqual(x, 0.))
    result = 1.570796;
  else if (x > 0. && x < 1.) {
    x = s21_sqrt(1 - x * x) / x;
    result = s21_atan(x);
  } else if (x < 0. && x > -1.) {
    x = s21_sqrt(1 - x * x) / x;
    result = s21_PI + s21_atan(x);
  }
  return result;
}