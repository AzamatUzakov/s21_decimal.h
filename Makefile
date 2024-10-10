# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -g -fprofile-arcs -ftest-coverage -std=c11
AR = ar
ARFLAGS = rcs

# Цели
TARGET = s21_decimal.a
TEST_TARGET = s21_decimal_test.a

# Исходные файлы
SRC = s21_add.c s21_sub.c s21_mul.c s21_div.c s21_is_less.c \
      s21_is_less_or_equal.c s21_is_greater.c s21_is_greater_or_equal.c \
      s21_is_equal.c s21_is_not_equal.c s21_from_int_to_decimal.c \
      s21_from_float_to_decimal.c s21_from_decimal_to_int.c \
      s21_from_decimal_to_float.c s21_floor.c s21_round.c \
      s21_truncate.c s21_negate.c

OBJS = $(SRC:.c=.o)

# Тестовый файл
TEST_SRC = tests.c
TEST_OBJ = $(TEST_SRC:.c=.o)

# Флаги для тестов и покрытия
TEST_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
GCOVFLAGS = --coverage -Wall -Wextra -Werror

# Сборка основной библиотеки
$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Сборка тестовой цели
$(TEST_TARGET): $(TARGET)
	cp $(TARGET) $(TEST_TARGET)

# Компиляция тестов и запуск
test: $(TEST_TARGET) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_SRC) -o test_program $(TEST_FLAGS) $(TEST_TARGET)
	./test_program

# Генерация отчета покрытия
gcov_report: test
	rm -f *.g*
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) $(TARGET) $(TEST_FLAGS) $(GCOVFLAGS) -o test_program
	./test_program
	lcov -t "test_program" -o rep.info -c -d .
	genhtml -o gcov_report rep.info
	xdg-open gcov_report/index.html || open gcov_report/index.html
	rm -rf *.gcda *.gcno *.gcov rep.info

# Очистка
clean:
	rm -rf *.o *.g* *.info *.out gcov_report *.a *.dSYM test_program
	rm -f $(TARGET) $(TEST_TARGET)

# Форматирование кода (если нужно)
clang_format:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -i --style=Google *.c *.h tests.c
	rm -rf .clang-format

# Основные цели
all: clean $(TARGET)

.PHONY: clean test gcov_report all clang_format
