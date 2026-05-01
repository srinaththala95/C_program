#include <stdio.h>
#include <stdbool.h>

bool is_power_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main(void) {
    int values[] = {0, 1, 2, 3, 4, 8, 10, 16};
    int count = (int)(sizeof(values) / sizeof(values[0]));
    int index;

    for (index = 0; index < count; index++) {
        printf("%d is %sa power of 2\n", values[index],
               is_power_of_two(values[index]) ? "" : "not ");
    }

    return 0;
}
