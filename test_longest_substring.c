#include "longest_substring.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESULT_SIZE 128

static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_LONGEST(input, expected)                                           \
    do {                                                                          \
        char actual[RESULT_SIZE];                                                 \
        int status = longest_unique_alpha_substring((input), actual, sizeof(actual)); \
        tests_run++;                                                              \
        if (status != 1 || strcmp(actual, (expected)) != 0) {                     \
            tests_failed++;                                                       \
            printf("FAIL: longest_unique_alpha_substring(\"%s\") expected "      \
                   "status 1 and \"%s\", got status %d and \"%s\"\n",           \
                   (input), (expected), status, actual);                          \
        }                                                                         \
    } while (0)

#define ASSERT_INVALID(input)                                                     \
    do {                                                                          \
        char actual[RESULT_SIZE] = "unchanged";                                  \
        int status = longest_unique_alpha_substring((input), actual, sizeof(actual)); \
        tests_run++;                                                              \
        if (status != -1) {                                                       \
            tests_failed++;                                                       \
            printf("FAIL: expected invalid input to return -1, got status %d "    \
                   "and result \"%s\"\n", status, actual);                       \
        }                                                                         \
    } while (0)

#define ASSERT_BUFFER_FAILURE(input, buffer_size)                                 \
    do {                                                                          \
        char actual[RESULT_SIZE] = "unchanged";                                  \
        int status = longest_unique_alpha_substring((input), actual, (buffer_size)); \
        tests_run++;                                                              \
        if (status != -1) {                                                       \
            tests_failed++;                                                       \
            printf("FAIL: expected buffer size %zu for \"%s\" to return -1, "    \
                   "got status %d and result \"%s\"\n",                         \
                   (size_t)(buffer_size), (input), status, actual);               \
        }                                                                         \
    } while (0)

static void test_basic_examples(void) {
    ASSERT_LONGEST("abcabcbb", "abc");
    ASSERT_LONGEST("bbbbb", "b");
    ASSERT_LONGEST("pwwkew", "wke");
    ASSERT_LONGEST("abcdedabc", "abcde");
}

static void test_empty_and_single_character_strings(void) {
    ASSERT_LONGEST("", "");
    ASSERT_LONGEST("a", "a");
    ASSERT_LONGEST("Z", "Z");
}

static void test_case_sensitivity(void) {
    ASSERT_LONGEST("aA", "aA");
    ASSERT_LONGEST("aAaA", "aA");
    ASSERT_LONGEST("abcABCabc", "abcABC");
}

static void test_long_unique_strings(void) {
    ASSERT_LONGEST("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz");
    ASSERT_LONGEST("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    ASSERT_LONGEST("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
                   "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

static void test_repeats_and_ties(void) {
    ASSERT_LONGEST("abca", "abc");
    ASSERT_LONGEST("abcda", "abcd");
    ASSERT_LONGEST("dvdf", "vdf");
    ASSERT_LONGEST("abba", "ab");
    ASSERT_LONGEST("abcdeedcba", "abcde");
    ASSERT_LONGEST("abcbdef", "cbdef");
}

static void test_invalid_inputs(void) {
    ASSERT_INVALID(NULL);
    ASSERT_INVALID("abc def");
    ASSERT_INVALID("abc123");
    ASSERT_INVALID("abc_def");
    ASSERT_INVALID("abc-def");
    ASSERT_INVALID("abc!");
    ASSERT_INVALID("abc\n");
    ASSERT_INVALID("abc.def");
}

static void test_invalid_output_buffers(void) {
    char actual[RESULT_SIZE];

    tests_run++;
    if (longest_unique_alpha_substring("abc", NULL, RESULT_SIZE) != -1) {
        tests_failed++;
        printf("FAIL: expected NULL result buffer to return -1\n");
    }

    ASSERT_BUFFER_FAILURE("abc", 0);
    ASSERT_BUFFER_FAILURE("abc", 3);

    tests_run++;
    if (longest_unique_alpha_substring("", actual, sizeof(actual)) != 1 ||
        strcmp(actual, "") != 0) {
        tests_failed++;
        printf("FAIL: expected empty string to succeed with empty result\n");
    }
}

int main(void) {
    test_basic_examples();
    test_empty_and_single_character_strings();
    test_case_sensitivity();
    test_long_unique_strings();
    test_repeats_and_ties();
    test_invalid_inputs();
    test_invalid_output_buffers();

    if (tests_failed == 0) {
        printf("All %d tests passed.\n", tests_run);
        return EXIT_SUCCESS;
    }

    printf("%d of %d tests failed.\n", tests_failed, tests_run);
    return EXIT_FAILURE;
}
