#include "longest_substring.h"

#include <stddef.h>
#include <string.h>

static int is_ascii_alpha(unsigned char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int longest_unique_alpha_substring(const char *input, char *result, size_t result_size) {
    size_t last_seen[128];
    size_t window_start = 0;
    size_t best_start = 0;
    size_t best_length = 0;
    size_t index;

    if (input == NULL || result == NULL || result_size == 0) {
        return -1;
    }

    result[0] = '\0';

    for (index = 0; index < 128; index++) {
        last_seen[index] = (size_t)-1;
    }

    for (index = 0; input[index] != '\0'; index++) {
        unsigned char ch = (unsigned char)input[index];
        size_t current_length;

        if (!is_ascii_alpha(ch)) {
            return -1;
        }

        if (last_seen[ch] != (size_t)-1 && last_seen[ch] >= window_start) {
            window_start = last_seen[ch] + 1;
        }

        last_seen[ch] = index;
        current_length = index - window_start + 1;

        if (current_length > best_length) {
            best_start = window_start;
            best_length = current_length;
        }
    }

    if (best_length + 1 > result_size) {
        return -1;
    }

    memcpy(result, input + best_start, best_length);
    result[best_length] = '\0';

    return 1;
}
