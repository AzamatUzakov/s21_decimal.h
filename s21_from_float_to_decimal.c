#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  dst->bits[0] = (int)src;  // Упростим для примера
  dst->bits[1] = 0;         // Установить порядок
  dst->bits[2] = 0;         // Установить флаг
  dst->bits[3] = 0;         // Установить флаг
  return 0;                 // Успех
}
