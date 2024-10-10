#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  // Реализация вычитания
  unsigned long long int_val1 = (unsigned long long)value_1.bits[0];
  unsigned long long int_val2 = (unsigned long long)value_2.bits[0];

  // Проверка на переполнение
  if (int_val1 < int_val2) {
    return 1;  // Переполнение
  }

  result->bits[0] = int_val1 - int_val2;  // Вычисляем результат
  result->bits[1] =
      value_1.bits[1];  // Дополнительно обработать знаки и порядок
  result->bits[2] = value_1.bits[2];  // Установить порядок
  result->bits[3] = 0;                // Установить флаг
  return 0;                           // Успех
}
