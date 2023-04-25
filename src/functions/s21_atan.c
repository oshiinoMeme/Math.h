#include "../s21_math.h"

long double s21_atan(double x) {
  long double sum_result = 0;
  if (isEqual(x, 1.) || isEqual(x, -1.)) {
    sum_result = 0.785398 * x;
  } else if (s21_fabs(x) < 1.) {
    for (int i = 0; i < 5000; i++) {
      int a = 1 + 2 * i;
      int minusOneDegree = (i % 2 == 0) ? 1 : -1;
      sum_result += (minusOneDegree * s21_pow(x, a)) / a;
    }
  } else {
    for (int i = 0; i < 7000; i++) {
      int a = 1 + 2 * i;
      int minusOneDegree = (i % 2 == 0) ? 1 : -1;
      sum_result += (minusOneDegree * s21_pow(x, -a)) / a;
    }
    sum_result = ((s21_PI * s21_sqrt(s21_pow(x, 2))) / (2 * x)) - sum_result;
  }
  if (x > 0 && s21_ISINF(x)) {
    sum_result = 1.5707963267;
  } else if (x < 0 && s21_ISINF(x)) {
    sum_result = -1.5707963267;
  }
  return sum_result;
}