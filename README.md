*This project has been created as part of the 42 curriculum by lmatthes.*

# ft_printf

## 📌 Description

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

<!-- ### Example Usage

``` c
#include "ft_printf.h"

int main(void)
{
    char            *name = "Gengar";
    int             level = 48;
    unsigned int    hp = 127;
    void            *ptr = name;

    ft_printf("-- Pokémon Summary --\n");
    ft_printf("Pokémon : %s\n", name);
    ft_printf("Level : %d\n", level);
    ft_printf("HP : %u\n", hp);
    ft_printf("Memory location : %p\n", ptr);
    ft_printf("Pokédex (hex) : %X\n", 94);

    return (0);
}

``` -->

## 🔗 Resources

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

1. Iterate through the format string.
2. Print normal characters directly.
3. On encountering `%`, read the next character to determine the conversion type.
4. Call the corresponding helper function (`ft_putchar`, `ft_putnbr`, etc.).
5. Each helper returns the number of characters printed.
5. Accumulate and return the total printed count.

This mirrors the core behavior of `printf()` while keeping implementation simple and modular.
