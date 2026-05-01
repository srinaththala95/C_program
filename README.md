# C Program Examples

Small C programs and tests.

## Power of Two

`bit_operations.c` demonstrates checking whether a signed integer is a power of two using bit operations.

```c
return n > 0 && (n & (n - 1)) == 0;
```

The function returns `true` only for positive powers of two. Zero and negative numbers return `false`.

## Build and Run

Build and run the demo:

```bash
make
./hello
```

Build and run the tests:

```bash
gcc -Wall -Wextra -Werror -std=c11 -o test_power_of_two test_power_of_two.c
./test_power_of_two
```

On Windows PowerShell, run `./hello.exe` and `./test_power_of_two.exe`.

## Complexity

For `is_power_of_two(int n)`:

- Time complexity: `O(1)`
- Space complexity: `O(1)`
