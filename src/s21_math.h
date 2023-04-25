#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define s21_EXP 2.71828182845904523536028747135266250
#define s21_PI 3.14159265358979324
#define MAX_LONG_DOUBLE 1.79769313486231571e+308
#define MAX_DOUBLE 1.79769313486231571e+308
#define s21_INF 1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_EPS 1e-6
#define s21_ISNAN(x) (!(x >= 0) && !(x < 0))

int s21_abs(int x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_floor(double x);
long double s21_fabs(double x);
long double s21_sqrt(double x);
long double s21_cos(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
int s21_ISINF(double x);

double factor(int x);
int isEqual(double a, double b);
