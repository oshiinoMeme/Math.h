#include "../s21_math.h"

long double s21_tan(double x) {
  long double res;
  if (x == s21_PI / 2) {
    res = 16331239353195370.0;
  } else if (x == -s21_PI / 2) {
    res = -16331239353195370.0;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}