#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0.0;
  if (x > MAX_DOUBLE) {
    result = s21_INF;
  } else if (x == 0) {
    result = 0.0;
  } else if (x > 0) {
    long double xn = x / 2.0;
    for (int i = 0; i < 1000; i++) {
      xn = (xn + x / xn) / 2.0;
    }
    result = xn;
  } else {
    result = s21_NAN;
  }
  return result;
}