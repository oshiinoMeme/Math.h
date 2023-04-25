#include "../s21_math.h"

long double pow_for_int(double base, long int exp) {
  long double res = 1;
  while (exp) {
    if (exp % 2) res = (exp > 0) ? (res * base) : (res / base);
    base *= base;
    exp /= 2;
  }
  return res;
}

long double pow_for_float(double base, double exp) {
  long double res = s21_exp(s21_log(base) * exp);
  for (int i = 0; i < 10; i++) {
    long double inc = (s21_log(res) - s21_log(base) * exp) * res;
    if (inc != inc) break;
    res = res - inc;
  }
  return res;
}

long double pow_helper(double base, double exp) {
  long double res = 0;
  if (base == 1.)
    res = 1;
  else if (exp == 0.)
    res = 1;
  else if (s21_ISNAN(base))
    res = s21_NAN;
  else if (base == 0. && !s21_ISNAN(exp))
    res = (exp < 0.) ? s21_INF : 0;
  else if (base == -1. && s21_ISINF(exp))
    res = 1.0;
  else if (exp == s21_INF)
    res = (s21_fabs(base) < 1.) ? 0 : s21_INF;
  else if (exp == -s21_INF)
    res = (s21_fabs(base) < 1.) ? s21_INF : 0;
  else if (base == -s21_INF && !s21_ISNAN(exp))
    res = (exp < 0) ? 0 : s21_INF;
  else
    res = pow_for_float(base, exp);
  return res;
}

long double s21_pow(double base, double exp) {
  long double result = 0;
  long double copy_exp_int = (long long int)exp;
  if (!(exp - copy_exp_int) && !s21_ISNAN(exp) && !s21_ISNAN(base))
    result = pow_for_int(base, exp);
  else
    result = pow_helper(base, exp);
  return result;
}