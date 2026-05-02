CC := gcc
CFLAGS := -Wall -Wextra -Werror -std=c11

.PHONY: all clean test

all: hello

hello: bit_operations.c
	$(CC) $(CFLAGS) -o hello bit_operations.c

test: test_power_of_two test_longest_substring
	./test_power_of_two
	./test_longest_substring

test_power_of_two: test_power_of_two.c
	$(CC) $(CFLAGS) -o test_power_of_two test_power_of_two.c

test_longest_substring: test_longest_substring.c longest_substring.c longest_substring.h
	$(CC) $(CFLAGS) -o test_longest_substring test_longest_substring.c longest_substring.c

clean:
	rm -f hello hello.exe test_power_of_two test_power_of_two.exe test_longest_substring test_longest_substring.exe
