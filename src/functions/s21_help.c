#include "../s21_math.h"

double factor(int x) {
  double res = 1;
  for (int i = 1; i <= x; i++) res *= i;
  return res;
}

int isEqual(double a, double b) {
  int res = 0;
  if (s21_fabs(a - b) < 1e-6) res = 1;
  return res;
}

int s21_ISINF(double x) { return ((x == s21_INF) || (x == -s21_INF)); }