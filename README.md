# C Program Examples

Small C programs and tests.

## Power of Two

`bit_operations.c` demonstrates checking whether a signed integer is a power of two using bit operations.

```c
return n > 0 && (n & (n - 1)) == 0;
```

The function returns `true` only for positive powers of two. Zero and negative numbers return `false`.

## Longest Substring Without Repeating Characters

`longest_substring.c` finds the longest substring without repeating characters in `O(n)` time.

```c
int status = longest_unique_alpha_substring(input, result, result_size);
```

The function returns `1` on success and writes the substring into the caller-provided
`result` buffer. It returns `-1` when the input is `NULL`, the result buffer is
invalid, the result buffer is too small, or the string contains any character
outside `a-z` or `A-Z`.

## Build and Run

Build and run the demo:

```bash
make
./hello
```

Build and run the tests:

```bash
make test
```

On Windows PowerShell without `make`, build and run the new substring tests with:

```powershell
gcc -Wall -Wextra -Werror -std=c11 -o test_longest_substring test_longest_substring.c longest_substring.c
./test_longest_substring.exe
```

Run compiled executables with `./hello.exe`, `./test_power_of_two.exe`, and
`./test_longest_substring.exe`.

## Complexity

For `is_power_of_two(int n)`:

- Time complexity: `O(1)`
- Space complexity: `O(1)`

For `longest_unique_alpha_substring(const char *input, char *result, size_t result_size)`:

- Time complexity: `O(n)`
- Space complexity: `O(1)` auxiliary lookup space, using caller-provided result storage.
