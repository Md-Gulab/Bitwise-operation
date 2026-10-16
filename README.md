# Bit Manipulation Toolkit in C

A small, dependency-free C project demonstrating bitwise operations on 32-bit unsigned integers. Useful for learning bit tricks, and for the register and flag manipulation common in embedded software work.

## Features

| Function | Description |
|----------|-------------|
| `set_bit()` | Sets a bit to 1 |
| `clear_bit()` | Clears a bit to 0 |
| `toggle_bit()` | Flips a bit |
| `check_bit()` | Returns 1 if a bit is set, else 0 |
| `count_set_bits()` | Counts the number of 1 bits |
| `is_power_of_two()` | Checks whether a number is a power of two |
| `print_binary()` | Prints a number in 32-bit binary |

## Getting Started

### Prerequisites

- GCC (or any C compiler)
- Make (optional)

### Build and run

```bash
git clone https://github.com/Md-Gulab/Bitwise-operation.git
make
```

Or compile directly:

```bash
gcc -Wall -Wextra -o main.c main
./main.exe
```

## Usage

```c
uint32_t n = 10;              // 1010

n = set_bit(n, 0);            // 1011  (11)
n = clear_bit(n, 3);          // 0011  (3)
n = toggle_bit(n, 2);         // 0111  (7)

print_binary(n);
printf("Bit 1 set? %d\n", check_bit(n, 1));         // 1
printf("Set bits:  %d\n", count_set_bits(n));        // 3
printf("Power of two? %d\n", is_power_of_two(64));   // 1
```

## API Reference

Bit positions are zero-indexed from the least significant bit (0–31).

```c
uint32_t set_bit(uint32_t num, uint8_t pos);
uint32_t clear_bit(uint32_t num, uint8_t pos);
uint32_t toggle_bit(uint32_t num, uint8_t pos);
int      check_bit(uint32_t num, uint8_t pos);
int      count_set_bits(uint32_t num);
int      is_power_of_two(uint32_t num);
void     print_binary(uint32_t num);
```

## Project Structure

```
.
├── src/
│   ├── bit_manipulation.c    # Bitwise function implementations
│   ├── bit_manipulation.h    # Header guards and function prototypes
│   └── main.c                # Main application entry and testing
├── .gitignore                # Git ignore rules
├── Makefile                  # Build and compilation automation
└── README.md                 # Project documentation
```