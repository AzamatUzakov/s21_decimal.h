#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  *dst = src.bits[0];  // Упростим для примера
  return 0;            // Успех
}
