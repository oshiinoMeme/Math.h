#include "../s21_math.h"

long double s21_sin(double x) { return s21_cos(x - s21_PI / 2); }
