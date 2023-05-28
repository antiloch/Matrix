CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TEST_FLAGS = -lcheck

BUILD_DIR=build
BUILD_TEST_DIR=$(BUILD_DIR)/tests
BUILD_FUNC_DIR=$(BUILD_DIR)/s21_func
SRCS=$(wildcard s21_*.c s21_func/s21_*.c)
OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)
TEST_SRCS=$(wildcard tests/*.c)

LIB_NAME=s21_matrix.a

all: clean $(LIB_NAME) 

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_FUNC_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME): $(OBJS)
	@echo "\033[1;34mCreating $(LIB_NAME) library\033[0m"
	@ar rc $(LIB_NAME) $^
	@ranlib $(LIB_NAME)
	@echo "\033[1;42m DONE \033[0m"

test: $(LIB_NAME)
	@echo "\033[1;34mCreating tests\033[0m"
	@$(CC) $(FLAGS) $(TEST_SRCS) -L. $(LIB_NAME) $(TEST_FLAGS) -o test
	@./test

add_coverage_flag:
	$(eval FLAGS += --coverage)	

gcov_report: clean add_coverage_flag test
	@gcov -l -p $(BUILD_DIR)/*.gcno
	@rm -rf *.gcno *gcda *.gcov
	@lcov -q --c --directory . --output-file coverage.info
	@genhtml -q coverage.info --output-directory gcov_report
	@open gcov_report/index.html

clean:
	@echo "\033[1;34mCleaning\033[0m"
	@rm -rf build/ gcov_report/
	@rm -rf a.out test *.info *.a *.gcda
	@echo "\033[1;42m DONE \033[0m"

style: 
	@echo "\033[1;34mStyling\033[0m"
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.h
	@clang-format -i s21_func/*.c
	@clang-format -i tests/*.c tests/*.h
	@rm .clang-format
	@echo "\033[1;42m DONE \033[0m"

leaks:
	@leaks -atExit -- ./test