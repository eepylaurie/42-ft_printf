*This project has been created as part of the 42 curriculum by lmatthes.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library's `printf()` function,
compiled into the static library `libftprintf.a`. It reproduces the formatted-output
behavior of the original for the following conversions:

| Conversion | Output |
|------------|--------------------------------------------|
| `%c`       | a single character                         |
| `%s`       | a string (`(null)` when the pointer is NULL) |
| `%p`       | a pointer address in hexadecimal, `0x`-prefixed (`(nil)` when NULL) |
| `%d` / `%i`| a signed base-10 integer                   |
| `%u`       | an unsigned base-10 integer                |
| `%x` / `%X`| an unsigned integer in lower/upper hexadecimal |
| `%%`       | a literal percent sign                     |

Like the original, `ft_printf` returns the total number of characters written. The project's goal is to explore **variadic functions** in C (`va_start`, `va_arg`,
`va_copy`, `va_end`) and to produce well-structured, extensible code.

This implementation supports only the mandatory conversions above; it intentionally
does not implement flags, field width, precision, or length modifiers. Its behavior
was compared against the system `printf` on Linux, which is why outputs such as
`(nil)` for a NULL pointer are used.

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
| `clean`   | removes object files                      |
| `fclean`  | removes object files and the library      |
| `re`      | runs `fclean` then `all`                  |

The library is compiled with `-Wall -Wextra -Werror` using `cc`, and the archive is
created with `ar`.

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

The implementation follows a simple streaming approach: there is **no buffer**.
`ft_printf` walks the format string one character at a time and writes output
immediately via `write`. Each output helper reports how many characters it wrote as
its return value, and `ft_printf` adds those counts into a running `count`. Because
every helper reports its own length, the total return value is obtained naturally — there is no separate length calculation anywhere in the code.

### Control flow

The main loop in `ft_printf` scans the format string. On encountering a `%` followed
by another character, it advances and hands the specifier to `ft_format`, which acts
as a dispatch table: a chain of comparisons mapping each specifier to its output
helper, retrieving the matching argument with `va_arg` using the correct type. Any
non-`%` character is written literally. A trailing lone `%` (undefined behavior in the
reference `printf`) is treated as a literal `%`.

### Number conversion

Signed decimals (`%d`/`%i`), unsigned decimals (`%u`), and hexadecimals (`%x`/`%X`,
`%p`) all use the same recursive strategy: divide by the base, recurse on the quotient,
then print the remainder. Recursing *before* printing the remainder emits the digits
in the correct order without needing a temporary buffer.

Type choices matter here and are the reason the numeric helpers are not all one
function:

- **`%d`/`%i`** operate on `int`. `INT_MIN` (`-2147483648`) is handled as a special
  case, because negating it overflows the `int` range — its positive value does not
  fit in an `int`.
- **`%u`** operates on `unsigned int`, so values above `INT_MAX` print correctly
  instead of wrapping negative.
- **`%x`/`%X`** operate on `unsigned int` and select their digit alphabet
  (`0123456789abcdef` or the uppercase variant) via a base string passed as a
  parameter — the lookup `base[n % 16]` maps a digit to its character with no branching.
- **`%p`** operates on `unsigned long`, because pointers are 64-bit and an
  `unsigned int` would truncate the address. It prints a `0x` prefix, and a NULL
  pointer is rendered as `(nil)` to match the reference implementation on Linux.

### File organization

```text
.
├── ft_printf.h
├── ft_printf.c
├── ft_format.c
├── ft_putchar.c
├── ft_putnbr.c
├── ft_puthex.c
└── Makefile
```

Functions are grouped into purpose-named files, each kept within the Norm's
five-function-per-file limit:

| File                | Contents                                      |
|---------------------|-----------------------------------------------|
| `ft_printf.c`       | `ft_printf` — the entry point and parse loop  |
| `ft_format.c`       | `ft_format` — the specifier dispatch table    |
| `ft_putchar.c`      | character and string output                   |
| `ft_putnbr.c`       | signed and unsigned decimal output            |
| `ft_puthex.c`       | hexadecimal and pointer output                |
| `ft_printf.h`       | prototypes                                     |

No dynamic data structure is used: the entire implementation is stateless and
character-driven, which keeps memory management trivial (there is nothing to free) and
the code easy to reason about.

## Resources

Documentation and references used while working on this project:

- `man 3 printf` — the reference behavior this project reproduces
- `man 3 stdarg` — the variadic-argument macros (`va_start`, `va_arg`, `va_copy`, `va_end`)
- The C standard's treatment of default argument promotions (why `%c` retrieves an `int`)

### Use of AI

AI was used as a learning and documentation aid. It helped explain concepts such as variadic functions, recursion, integer edge cases, and assisted with improving the project's documentation. The implementation, debugging, testing, and design decisions were completed independently.