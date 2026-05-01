#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_POWER_OF_TWO(input, expected)                                      \
    do {                                                                          \
        bool actual = is_power_of_two((input));                                   \
        tests_run++;                                                              \
        if (actual != (expected)) {                                               \
            tests_failed++;                                                       \
            printf("FAIL: is_power_of_two(%d) expected %s, got %s\n",            \
                   (input), (expected) ? "true" : "false",                      \
                   actual ? "true" : "false");                                  \
        }                                                                         \
    } while (0)

bool is_power_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

static void test_zero_is_not_power_of_two(void) {
    ASSERT_POWER_OF_TWO(0, false);
}

static void test_negative_numbers_are_not_power_of_two(void) {
    ASSERT_POWER_OF_TWO(-1, false);
    ASSERT_POWER_OF_TWO(-2, false);
    ASSERT_POWER_OF_TWO(-8, false);
    ASSERT_POWER_OF_TWO(INT_MIN, false);
}

static void test_positive_powers_of_two(void) {
    ASSERT_POWER_OF_TWO(1, true);
    ASSERT_POWER_OF_TWO(2, true);
    ASSERT_POWER_OF_TWO(4, true);
    ASSERT_POWER_OF_TWO(8, true);
    ASSERT_POWER_OF_TWO(16, true);
    ASSERT_POWER_OF_TWO(1024, true);
    ASSERT_POWER_OF_TWO(1073741824, true);
}

static void test_positive_non_powers_of_two(void) {
    ASSERT_POWER_OF_TWO(3, false);
    ASSERT_POWER_OF_TWO(5, false);
    ASSERT_POWER_OF_TWO(6, false);
    ASSERT_POWER_OF_TWO(7, false);
    ASSERT_POWER_OF_TWO(9, false);
    ASSERT_POWER_OF_TWO(10, false);
    ASSERT_POWER_OF_TWO(INT_MAX, false);
}

int main(void) {
    test_zero_is_not_power_of_two();
    test_negative_numbers_are_not_power_of_two();
    test_positive_powers_of_two();
    test_positive_non_powers_of_two();

    if (tests_failed == 0) {
        printf("All %d tests passed.\n", tests_run);
        return EXIT_SUCCESS;
    }

    printf("%d of %d tests failed.\n", tests_failed, tests_run);
    return EXIT_FAILURE;
}
