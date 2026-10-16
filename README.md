# Bit Manipulation Toolkit in C

A small C project demonstrating bitwise operations on 32-bit unsigned integers, with unit tests written using the [Unity](https://github.com/ThrowTheSwitch/Unity) framework. Useful for learning bit tricks, and for the register and flag manipulation common in embedded software work.

## Features

| Function | Description |
|----------|-------------|
| `set_bit()` | Sets a bit to 1 |
| `clear_bit()` | Clears a bit to 0 |
| `toggle_bit()` | Flips a bit |
| `check_bit()` | Returns `true` if a bit is set, else `false` |
| `count_set_bits()` | Counts the number of 1 bits |
| `is_power_of_two()` | Checks whether a number is a power of two |
| `print_binary()` | Prints a number in 32-bit binary |

## Project Structure

```
.
├── src/
│   ├── bit_manipulation.c       # Bitwise function implementations
│   ├── bit_manipulation.h       # Header guards and function prototypes
│   └── main.c                   # Demo program that prints example results
├── test/
│   └── test_bit_manipulation.c  # Unity unit tests (17 tests, has its own main())
├── unity/                       # Unity test framework (third-party, MIT licensed)
│   ├── auto/                    # Helper scripts (e.g. test runner generator)
│   ├── src/                     # unity.c, unity.h, unity_internals.h
│   ├── LICENSE.txt
│   └── README.md
├── .gitignore                   # Git ignore rules
├── Makefile                     # Build, run and test automation
├── README.md                    # Project documentation

```

## Getting Started

### Prerequisites

- GCC with `-std=c2x` support (GCC 13 was used for development)
- Make

The provided Makefile is written for MinGW-w64 on Windows (it links `-lucrt` and produces `.exe` files). On Linux or macOS, remove `-lucrt` from the Makefile and drop the `.exe` extensions.

### Build and run

```bash
git clone https://github.com/Md-Gulab/Bitwise-operation.git
cd Bitwise-operation
make          # builds the demo program
make run      # runs it
```

Or compile directly:

```bash
gcc -std=c2x -Wall -Wextra -Wpedantic src/main.c src/bit_manipulation.c -o main
./main
```

### Makefile targets

| Command | What it does |
|---------|--------------|
| `make` or `make compile` | Builds the demo program (`main`) from `src/` |
| `make run` | Runs the demo program |
| `make test` | Builds and runs the Unity unit tests |
| `make clean` | Removes the built executables |

## Usage

```c
#include <stdio.h>
#include "bit_manipulation.h"

int main(void)
{
    uint32_t n = 10;              // 1010

    n = set_bit(n, 0);            // 1011  (11)
    n = clear_bit(n, 3);          // 0011  (3)
    n = toggle_bit(n, 2);         // 0111  (7)

    print_binary(n);
    printf("Bit 1 set? %d\n", check_bit(n, 1));         // 1
    printf("Set bits:  %d\n", count_set_bits(n));        // 3
    printf("Power of two? %d\n", is_power_of_two(64));   // 1
    return 0;
}
```

## API Reference

Bit positions are zero-indexed from the least significant bit (0–31). Positions outside that range are not validated; shifting by 32 or more bits is undefined behavior in C.

```c
uint32_t set_bit(uint32_t num, uint32_t pos);
uint32_t clear_bit(uint32_t num, uint32_t pos);
uint32_t toggle_bit(uint32_t num, uint32_t pos);
bool     check_bit(uint32_t num, uint32_t pos);
int      count_set_bits(uint32_t num);
bool     is_power_of_two(uint32_t num);
void     print_binary(uint32_t n);
```

## Testing

Unit tests use the Unity framework, which is bundled in the `unity/` folder, so nothing extra needs to be installed.

### Run the tests

```bash
make test
```

Or build and run them by hand:

```bash
gcc -std=c2x -Wall -Wextra -Wpedantic -Iunity/src -Isrc \
    test/test_bit_manipulation.c src/bit_manipulation.c unity/src/unity.c \
    -o test_bit_manipulation
./test_bit_manipulation
```

A successful run ends with:

```
-----------------------
17 Tests 0 Failures 0 Ignored
OK
```

A failing test reports the file, line, test name and the values involved, for example:

```
test/test_bit_manipulation.c:109:test_clear_bit_clears_a_set_bit:FAIL: Expected 0xFE Was 0xFF
```

The program's exit code is the number of failed tests, so it can be used directly in CI.

### What is tested

| Function | Tests |
|----------|-------|
| `set_bit` | Sets a clear bit, leaves an already-set bit unchanged, works on bit 31 |
| `clear_bit` | Clears a set bit, leaves an already-clear bit unchanged |
| `toggle_bit` | Flips 0 to 1, flips 1 to 0, toggling twice restores the original |
| `check_bit` | Returns true for a set bit, false for a clear bit |
| `count_set_bits` | Zero, all ones (32), `0xFFFFFFF0` (28) |
| `is_power_of_two` | True for 1, 2 and `0x8000`; false for 0 and non-powers (3, 6, `0xFFFFFFFF`) |

`print_binary` is not unit tested yet, because it only prints and has no return value to check.

### How the test build works

- `test/test_bit_manipulation.c` has its **own** `main()` that runs every test, so `src/main.c` is **not** compiled into the test program. Including both would cause a "multiple definition of `main`" linker error.
- The test program is built from three source files: the test file, `src/bit_manipulation.c` and `unity/src/unity.c`.
- `-Iunity/src -Isrc` tell the compiler where to find `unity.h` and `bit_manipulation.h`.

### Adding a new test

1. Add a function to `test/test_bit_manipulation.c`:
   ```c
   void test_set_bit_sets_bit_zero(void)
   {
       TEST_ASSERT_EQUAL_HEX32(0x01, set_bit(0, 0));
   }
   ```
2. Register it in `main()` at the bottom of the file, or it will never run:
   ```c
   RUN_TEST(test_set_bit_sets_bit_zero);
   ```
3. Run `make test` and check that the "Tests" count went up by one.

Tip: after writing a test, break the code on purpose once to confirm the test can actually fail.

## Design Notes

- The bit functions **return** their result instead of printing it. This keeps the logic testable, and printing is left to the caller (see `src/main.c`).
- `print_binary` is the only function intended to produce output.

## Third-Party Software

[Unity](https://github.com/ThrowTheSwitch/Unity) by ThrowTheSwitch is included in `unity/` and used under the MIT License. See `unity/LICENSE.txt`.

## Author:
## MD GULAB
    