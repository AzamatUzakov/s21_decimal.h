#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (value_2.bits[0] == 0) {
    return 1;  // Деление на ноль
  }
  unsigned long long int_val1 = ((unsigned long long)value_1.bits[0]) /
                                ((unsigned long long)value_2.bits[0]);
  result->bits[0] = (int)int_val1;
  result->bits[1] = value_1.bits[1] - value_2.bits[1];  // Вычитание порядков
  result->bits[2] = value_1.bits[2];  // Установить порядок
  result->bits[3] = 0;                // Установить флаг
  return 0;                           // Успех
}
