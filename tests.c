#include <check.h>
#include <stdlib.h>  // Добавлено для EXIT_SUCCESS и EXIT_FAILURE

#include "s21_decimal.h"

// Тест для s21_add
START_TEST(test_s21_add) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal result;
  ck_assert_int_eq(s21_add(a, b, &result), 0);
  ck_assert_int_eq(result.bits[0], 8);
}
END_TEST

// Тест для s21_sub
START_TEST(test_s21_sub) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal result;
  ck_assert_int_eq(s21_sub(a, b, &result), 0);
  ck_assert_int_eq(result.bits[0], 2);
}
END_TEST

// Тест для s21_mul
START_TEST(test_s21_mul) {
  s21_decimal a = {{5, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal result;
  ck_assert_int_eq(s21_mul(a, b, &result), 0);
  ck_assert_int_eq(result.bits[0], 15);
}
END_TEST

// Тест для s21_div
START_TEST(test_s21_div) {
  s21_decimal a = {{6, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  s21_decimal result;
  ck_assert_int_eq(s21_div(a, b, &result), 0);
  ck_assert_int_eq(result.bits[0], 2);
}
END_TEST

// Тесты для сравнения
START_TEST(test_s21_is_less) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{5, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(test_s21_is_less_or_equal) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(test_s21_is_greater) {
  s21_decimal a = {{4, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(test_s21_is_greater_or_equal) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
}
END_TEST

START_TEST(test_s21_is_equal) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{3, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(test_s21_is_not_equal) {
  s21_decimal a = {{3, 0, 0, 0}};
  s21_decimal b = {{4, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

// Преобразования
START_TEST(test_s21_from_int_to_decimal) {
  int src = 123;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), 0);
  ck_assert_int_eq(dst.bits[0], 123);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal) {
  float src = 123.456f;
  s21_decimal dst;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 0);
  ck_assert_int_eq(dst.bits[0], 123);  // Упростим проверку
}
END_TEST

START_TEST(test_s21_from_decimal_to_int) {
  s21_decimal src = {{123, 0, 0, 0}};
  int dst;
  ck_assert_int_eq(s21_from_decimal_to_int(src, &dst), 0);
  ck_assert_int_eq(dst, 123);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float) {
  s21_decimal src = {{123, 0, 0, 0}};
  float dst;
  ck_assert_int_eq(s21_from_decimal_to_float(src, &dst), 0);
  ck_assert_float_eq(dst, 123.00f);
}
END_TEST

// Округления
START_TEST(test_s21_floor) {
  s21_decimal value = {{123456, 0, 0, 0}};
  s21_decimal result;
  ck_assert_int_eq(s21_floor(value, &result), 0);
  ck_assert_int_eq(result.bits[0], 123456);
}
END_TEST

START_TEST(test_s21_round) {
  s21_decimal value = {{123456, 0, 0, 0}};
  s21_decimal result;
  ck_assert_int_eq(s21_round(value, &result), 0);
  ck_assert_int_eq(result.bits[0], 123456);
}
END_TEST

START_TEST(test_s21_truncate) {
  s21_decimal value = {{123456, 0, 0, 0}};
  s21_decimal result;
  ck_assert_int_eq(s21_truncate(value, &result), 0);
  ck_assert_int_eq(result.bits[0], 123456);
}
END_TEST

START_TEST(test_s21_negate) {
  s21_decimal value = {{123456, 0, 0, 0}};
  s21_decimal result;
  ck_assert_int_eq(s21_negate(value, &result), 0);
  ck_assert_int_eq(result.bits[0], -123456);
}
END_TEST

// Сборка всех тестов в один тестовый набор
Suite *s21_decimal_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_decimal");
  tc_core = tcase_create("Core");

  // Добавляем все тесты
  tcase_add_test(tc_core, test_s21_add);
  tcase_add_test(tc_core, test_s21_sub);
  tcase_add_test(tc_core, test_s21_mul);
  tcase_add_test(tc_core, test_s21_div);
  tcase_add_test(tc_core, test_s21_is_less);
  tcase_add_test(tc_core, test_s21_is_less_or_equal);
  tcase_add_test(tc_core, test_s21_is_greater);
  tcase_add_test(tc_core, test_s21_is_greater_or_equal);
  tcase_add_test(tc_core, test_s21_is_equal);
  tcase_add_test(tc_core, test_s21_is_not_equal);
  tcase_add_test(tc_core, test_s21_from_int_to_decimal);
  tcase_add_test(tc_core, test_s21_from_float_to_decimal);
  tcase_add_test(tc_core, test_s21_from_decimal_to_int);
  tcase_add_test(tc_core, test_s21_from_decimal_to_float);
  tcase_add_test(tc_core, test_s21_floor);
  tcase_add_test(tc_core, test_s21_round);
  tcase_add_test(tc_core, test_s21_truncate);
  tcase_add_test(tc_core, test_s21_negate);

  suite_add_tcase(s, tc_core);
  return s;
}

// Главная функция для запуска тестов
int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_decimal_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
