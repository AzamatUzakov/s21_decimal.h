#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = (float)src.bits[0];  // Упростим для примера
  return 0;                   // Успех
}
