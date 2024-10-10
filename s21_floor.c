#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  result->bits[0] = value.bits[0];  // Упростим для примера
  result->bits[1] = 0;              // Установить порядок
  result->bits[2] = 0;              // Установить флаг
  result->bits[3] = 0;              // Установить флаг
  return 0;                         // Успех
}
