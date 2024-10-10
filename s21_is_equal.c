#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  return (value_1.bits[0] == value_2.bits[0]) ? 1 : 0;
}
