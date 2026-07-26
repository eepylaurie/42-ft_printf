*This project has been created as part of the 42 curriculum by lmatthes.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library's `printf()` function, compiled into the static library `libftprintf.a`. It reproduces the formatted-output behavior of the original for the following conversions:

| Conversion | Output |
|------------|--------------------------------------------|
| `%c`       | a single character                         |
| `%s`       | a string (`(null)` when the pointer is NULL) |
| `%p`       | a pointer address in hexadecimal, `0x`-prefixed (`(nil)` when NULL) |
| `%d` / `%i`| a signed base-10 integer                   |
| `%u`       | an unsigned base-10 integer                |
| `%x` / `%X`| an unsigned integer in lower/upper hexadecimal |
| `%%`       | a literal percent sign                     |

Like the original, `ft_printf` returns the total number of characters written. The project's goal is to explore **variadic functions** in C (`va_start`, `va_arg`, `va_copy`, `va_end`) and to produce well-structured, extensible code.

The mandatory part supports the conversions above without flags, field width, precision, or length modifiers. The bonus part additionally supports the `-`, `0`, `.` (precision), `#`, `+`, and space flags together with minimum field width, under all conversions. Behavior was compared against glibc's `printf` on Linux, which is why outputs such as `(nil)` for a NULL pointer are used.

## Instructions

### Build

The project ships with a `Makefile`. From the repository root:

```sh
make
```

This produces `libftprintf.a` at the root of the repository.

Available rules:

| Rule      | Effect                                    |
|-----------|-------------------------------------------|
| `make`    | builds `libftprintf.a` (default `all`)    |
| `bonus`   | builds `libftprintf.a` with the bonus features |
| `clean`   | removes object files                      |
| `fclean`  | removes object files and the library      |
| `re`      | runs `fclean` then `all`                  |

The library is compiled with `-Wall -Wextra -Werror` using `cc`, and the archive is created with `ar`. The `bonus` rule rebuilds the library from the `bonus` sources; the mandatory and bonus versions are not built into the archive at the same time.

### Use

Include the header in your source and link against the library when compiling:

```c
#include "ft_printf.h"

int main(void)
{
    int count = ft_printf("Hello %s, you are number %d\n", "world", 42);
    ft_printf("%d characters were printed\n", count);
    return (0);
}
```

Compile your program together with the library:

```sh
cc main.c libftprintf.a -o my_program
```

## Design

### Core idea

The implementation follows a simple streaming approach: there is **no buffer**. `ft_printf` walks the format string one character at a time and writes output immediately via `write`. Each output helper reports how many characters it wrote as its return value, and `ft_printf` adds those counts into a running `count`. Because every helper reports its own length, the total return value is obtained naturally — no separate pass is required to determine the output length.

### Control flow

The main loop in `ft_printf` scans the format string. On encountering a `%` followed by another character, it advances and hands the specifier to `ft_format`, which acts as a dispatch table: a chain of comparisons mapping each specifier to its output helper, retrieving the matching argument with `va_arg` using the correct type. Any non-`%` character is written literally. A trailing lone `%` (undefined behavior in the reference `printf`) is treated as a literal `%`.

### Number conversion

Signed decimals (`%d`/`%i`), unsigned decimals (`%u`), and hexadecimals (`%x`/`%X`, `%p`) all use the same recursive strategy: divide by the base, recurse on the quotient, then print the remainder. Recursing *before* printing the remainder emits the digits in the correct order without needing a temporary buffer.

The choice of integer type is the reason the numeric helpers are not all implemented as a single function.

- **`%d`/`%i`** operate on `int`. `INT_MIN` (`-2147483648`) is handled as a special case, because negating it overflows the `int` range — its positive value does not fit in an `int`.
- **`%u`** operates on `unsigned int`, so values above `INT_MAX` print correctly instead of wrapping negative.
- **`%x`/`%X`** operate on `unsigned int` and select their digit alphabet (`0123456789abcdef` or the uppercase variant) via a base string passed as a parameter — the lookup `base[n % 16]` maps a digit to its character with no branching.
- **`%p`** operates on `unsigned long`, because pointers are 64-bit and an `unsigned int` would truncate the address. It prints a `0x` prefix, and a NULL pointer is rendered as `(nil)` to match the reference implementation on Linux.

### File organization

```text
.
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf_bonus.h
├── libft/
├── mandatory/
│   ├── ft_printf.c
│   ├── ft_format.c
│   ├── ft_putchar.c
│   ├── ft_putnbr.c
│   └── ft_puthex.c
└── bonus/
    ├── ft_printf_bonus.c
    ├── ft_parse_bonus.c
    ├── ft_dispatch_bonus.c
    ├── ft_nbr_bonus.c
    ├── ft_flags_bonus.c
    ├── ft_prec_bonus.c
    └── ft_width_bonus.c
```

Headers stay at the repository root, since `ft_printf.h` is what external code includes. The mandatory sources are grouped into `mandatory/`, each file kept within the Norm's five-function-per-file limit:

| File                       | Contents                                      |
|----------------------------|-----------------------------------------------|
| `mandatory/ft_printf.c`    | `ft_printf` — the entry point and parse loop  |
| `mandatory/ft_format.c`    | `ft_format` — the specifier dispatch table    |
| `mandatory/ft_putchar.c`   | character and string output                   |
| `mandatory/ft_putnbr.c`    | signed and unsigned decimal output            |
| `mandatory/ft_puthex.c`    | hexadecimal and pointer output                |

The mandatory part uses no dynamic data structure: it is stateless and character-driven, which keeps memory management trivial (there is nothing to free) and the code easy to reason about.

## Bonus

The bonus adds flags, field width, and precision under every conversion. This required a different design from the mandatory streaming approach, because flags and width can only be applied once the length of a conversion's output is known — the padding depends on it. The bonus therefore builds each conversion's output into an allocated string first, then applies the format around it, then writes.

### Data structure

The parsed format specification is stored in a small struct, `t_fmt`, filled in once per conversion before the argument is fetched:

```c
typedef struct s_fmt
{
    int minus;   // '-'  left-justify
    int zero;    // '0'  pad with zeros
    int hash;    // '#'  alternate form (0x / 0X prefix)
    int plus;    // '+'  force a sign on positive numbers
    int space;   // ' '  space before positive numbers
    int width;   // minimum field width
    int prec;    // precision (-1 when none is given)
    int is_num;  // set for numeric conversions
}   t_fmt;
```

A flat structure is the natural fit: the specification is a fixed set of independent attributes with no relationships between them, so there is nothing a list or tree would add. Passing one `t_fmt` by pointer keeps every stage's signature small and avoids threading many separate parameters through the pipeline. `prec` uses `-1` as a sentinel so that "no precision" is distinguishable from an explicit precision of `0` — a distinction that matters, since `%.0d` of `0` must print nothing. `is_num` lets the precision stage tell numeric conversions (precision means minimum digits) apart from strings (precision means truncation).

### Pipeline

Each conversion passes through the same ordered stages, and each stage returns a possibly-reallocated string:

1. **Build** — the conversion produces its raw output as an allocated string (`ft_itoa` for decimals, a base converter for unsigned and hexadecimal values, and the string or character directly for `%s`/`%c`).
2. **Flags** — a sign or space is prepended for signed numbers, or a `0x`/`0X` prefix for hexadecimal under `#`.
3. **Precision** — for numbers, zeros are inserted after any sign to reach the minimum digit count; for strings, the string is truncated. The two cases are mutually exclusive and selected by `is_num`.
4. **Width** — the string is padded with spaces (or zeros, when the `0` flag applies and neither `-` nor a precision overrides it) to reach the field width, on the left or right depending on `-`.

The zero-padding and the prefix handling are sign-aware: when zeros fill a field, any leading sign character or `0x` prefix is written first, so `%05d` of `-42` yields `-0042` rather than `00-42`, and `%#08x` of `255` yields `0x0000ff`. Each allocated string is freed once it has been written, so the bonus introduces no memory leaks.

### Bonus files

The bonus lives entirely in `bonus/` and `_bonus` files so the mandatory part is untouched:

| File                          | Contents                                          |
|-------------------------------|---------------------------------------------------|
| `bonus/ft_printf_bonus.c`     | the entry point and parse loop                    |
| `bonus/ft_parse_bonus.c`      | parsing flags, width, and precision into `t_fmt`  |
| `bonus/ft_dispatch_bonus.c`   | building each conversion's string and running the pipeline |
| `bonus/ft_nbr_bonus.c`        | unsigned, hexadecimal, and pointer conversion     |
| `bonus/ft_flags_bonus.c`      | the `#`, `+`, and space prefixes                  |
| `bonus/ft_prec_bonus.c`       | precision for numbers and strings                 |
| `bonus/ft_width_bonus.c`      | field-width padding                               |
| `ft_printf_bonus.h`           | prototypes and the `t_fmt` definition             |

The bonus is allowed to use `libft`; its sources and Makefile are copied into a `libft` folder, which the project's Makefile compiles first and then links into `libftprintf.a`.

## Resources

Documentation and references used while working on this project:

- `man 3 printf` — the reference behavior this project reproduces
- `man 3 stdarg` — the variadic-argument macros (`va_start`, `va_arg`, `va_copy`, `va_end`)
- The C standard's treatment of default argument promotions (why `%c` retrieves an `int`)

### Use of AI

AI was used as a learning and documentation aid. It helped explain concepts such as variadic functions, recursion, integer edge cases, and assisted with improving the project's documentation. The implementation, debugging, testing, and design decisions were completed independently.