#include "../s21_math.h"

long double s21_ceil(double x) {
  long double res = 0.0;
  if (x > MAX_DOUBLE) {
    res = s21_INF;
  } else if (x < -MAX_DOUBLE) {
    res = -s21_INF;
  } else if (x <= MAX_DOUBLE && x >= -MAX_DOUBLE) {
    if (s21_fmod(x, 1)) {
      res = (x > 0) ? (int)x + 1 : (int)x;
    } else {
      res = x;
    }
  } else {
    res = s21_NAN;
  }

  return res;
}