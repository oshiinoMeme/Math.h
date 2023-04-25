CC = gcc
EFLAGS = -Wall -Wextra -Werror -std=c11
CFLAGS = $(EFLAGS) -c
OFLAGS = $(EFLAGS) -o
S21_MATH_C = functions/*.c
S21_MATH_O = s21_*.o
S21_SUITE_C = tests/*.c
S21_SUITE_O = suite_*.o

all: clean test

s21_math.a:
	$(CC) $(CFLAGS) $(S21_MATH_C)
	ar r s21_math.a $(S21_MATH_O)
	rm -rf *.o
	ranlib s21_math.a

test: s21_math.a
	$(CC) $(CFLAGS) $(S21_SUITE_C) main.c
	$(CC) $(OFLAGS) test $(S21_SUITE_O) main.o s21_math.a -lcheck -lm
	# $(CC) $(OFLAGS) test $(S21_SUITE_O) main.o s21_math.a -lcheck -lm -lsubunit
	./test
	rm -rf *.o *.a

valgrind:	s21_math.a
	$(CC) $(CFLAGS) $(S21_SUITE_C) main.c
	$(CC) $(OFLAGS) test $(S21_SUITE_O) main.o s21_math.a -lcheck -lm -lsubunit
	rm -rf *.o
	valgrind --leak-check=full -s ./test

gcov_report:
	$(CC) --coverage $(CFLAGS) $(S21_MATH_C)
	ar r s21_math.a $(S21_MATH_O)
	ranlib s21_math.a
	$(CC) $(CFLAGS) $(S21_SUITE_C) main.c
	$(CC) --coverage $(OFLAGS) test $(S21_SUITE_O) main.o s21_math.a -lcheck -lm
	rm -rf *.o *.a
	./test
	# gcov s21*.gcda
	gcovr -r . --html --html-details -o report.html
	open report.html

check:
	cppcheck --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem ./
	clang-format -n *.c *.h

style_check:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c *.h functions/*.c tests/*.c
	rm .clang-format

style_fix:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.c *.h functions/*.c tests/*.c
	rm .clang-format

clean:
	rm -rf *.o *.a test tgtests *.gcda *.gcno *.gcov *.html *.css *.out

rebuild: clean all