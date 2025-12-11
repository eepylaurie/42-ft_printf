*This project has been created as part of the 42 curriculum by lmatthes.*

# ft_printf

## ℹ️ Description

`ft_printf` is a custom, simplified reimplementation of the standard C `printf()` function. It formats and prints various data types using **variadic arguments**, without relying on the original printf's internal buffering.

This project reinforces string parsing, type conversion, and modular C code design.

### Supported Conversions

| Format | Description |
| ------ | ----------- |
| `%c` | single character |
| `%s` | string (as defined by the common C convention) |
| `%p` | pointer address in hexadecimal format |
| `%d` | signed decimal number |
| `%i` | signed integer (same as `%d`) |
| `%u` | unsigned decimal number |
| `%x` | number in lowercase hexadecimal format |
| `%X` | number in uppercase hexadecimal format |
| `%%` | literal `%` character |

## ⚙️ Instructions

### Build the library

``` bash
make
```
This creates `libftprintf.a`.

### Use it in a program

``` C
#include "ft_printf.h"

int main(void)
{
	char    		*name = "Gengar";
	int				level = 100;
	unsigned int	hp = 261;
	int				dex = 94;
	void			*location = name;

    ft_printf("Pokédex Entry\n\n");
	ft_printf("Name : %s\n", name);
	ft_printf("Level : %d\n", level);
	ft_printf("HP : %u\n", hp);
	ft_printf("Kanto-Dex : %X\n", dex);
	ft_printf("Location : %p\n", location);
}
```

### Compile & Run

``` bash
cc main.c libftprintf.a -o program
./program
```

### Clean / Rebuild

``` bash
make clean
make fclean
make re
```

## 🌐 Resources

- `man 3 printf` - reference for expected behavior
- `man 3 stdarg` - variadic arguments
- [ft_printf | Guide](https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf)
- [Variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

### AI Usage

AI assistance was used **only for learning support**, including:
- developing a study plan to structure my learning of ft_printf
- small conceptual clarifications (e.g., difference between `%d` and `%i`, explanation of original printf's buffer logic, variadic function theory)
- learning Markdown

**All code logic, structure, and implementation were written and understood by me.**

## 🧠 Algorithm Overview

`ft_printf` uses a simple linear algorithm:

1. Iterate through the format string.
2. Print normal characters directly.
3. On encountering `%`, read the next character to determine the conversion type.
4. Call the corresponding helper function (`ft_putchar`, `ft_putnbr`, etc.).
5. Each helper returns the number of characters printed.
5. Accumulate and return the total printed count.

This mirrors the core behavior of `printf()` while keeping implementation simple and modular.

## 🧬 Data Structures

The implementation uses only simple data structures:
- the **format string** (input),
- a **loop** index,
- a **va_list** to access variadic arguments,
- small **local integers** for counting and number hangling.
These are sufficient because values are printed immediately without storing or buffering, keeping the design simple, efficient, and compliant with the project requirements.
