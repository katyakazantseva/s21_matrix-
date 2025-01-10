CFLAGS = -Wall -Werror -Wextra

all: clean s21_matrix_oop.a

s21_matrix_oop.a:
	gcc -c $(CFLAGS) -lstdc++ -std=c++17 s21_matrix_oop.cc -o s21_matrix_oop.o
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

clean:
	rm -rf *.o s21_matrix_oop.a
	rm -rf tests/*.o
	rm -rf *.gcda *.gcno report gcov_report.* gcov_report *.info

leaks: clean test
	leaks -atExit -- ./test

clang:
	clang-format -i --style=google *.cc *.h
	cp ../materials/linters/.clang-format ../src/.clang-format;
	clang-format -style=Google -n *.cc *.h;
	rm .clang-format

test: clean s21_matrix_oop.a
	gcc -c $(CFLAGS) tests/s21_test_matrix_oop.cc -o tests/s21_test_matrix_oop.o -pedantic -fsanitize=address
	gcc -lgtest -lstdc++ -std=c++17 s21_matrix_oop.a tests/s21_test_matrix_oop.o -o test -pedantic -fsanitize=address
	./test

gcov_report: clean
	gcc  --coverage tests/s21_test_matrix_oop.cc s21_matrix_oop.cc -o gcov_report -lgtest -lstdc++
	./gcov_report
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

install_lcov:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov