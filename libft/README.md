*This project has been created as part of the 42 curriculum by lmatthes.*

# libft

## Description

`libft` is a static C library (`libft.a`) that reimplements a selection of
standard C library functions and adds a set of extra utilities that are useful
across the 42 curriculum. It is the first project of the cursus and provides a reusable toolbox of
functions that later projects can link against.

The library is organised in three parts:

1. **libc functions** — reimplementations of common `<string.h>`, `<ctype.h>`
   and `<stdlib.h>` functions, prefixed with `ft_` (for example `strlen`
   becomes `ft_strlen`). Each follows the expected behaviour of the original function.
2. **Additional functions** — string and output helpers that are not part of the standard C library, or that exist in a different form (`ft_substr`, `ft_split`,
   `ft_itoa`, the `ft_put*_fd` family, and others).
3. **Linked list** — functions to create and manipulate a simple singly linked
   list built on the `t_list` structure.

No global variables are used, helper functions are kept `static` within their
files, and every function is written to comply with the 42 Norm.

## Instructions

The project ships with a `Makefile`. From the repository root:

```sh
make        # build libft.a
make clean  # remove object files
make fclean # remove object files and libft.a
make re     # rebuild from scratch
```

Sources compile with `cc -Wall -Wextra -Werror`, and the archive is produced
with `ar`.

To use the library in your own program, include the header and link the
archive:

```c
#include "libft.h"
```

```sh
cc main.c -L. -lft -o my_program
# or, linking the archive directly:
cc main.c libft.a -o my_program
```

## Library contents

**Part 1 — libc functions**

- Character classification: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`,
  `ft_isascii`, `ft_isprint`
- Case conversion: `ft_toupper`, `ft_tolower`
- Memory: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`,
  `ft_memcmp`
- Strings: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`,
  `ft_strncmp`, `ft_strnstr`
- Conversion: `ft_atoi`
- Allocation: `ft_calloc`, `ft_strdup`

**Part 2 — Additional functions**

- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`,
  `ft_strmapi`, `ft_striteri`
- Output to a file descriptor: `ft_putchar_fd`, `ft_putstr_fd`,
  `ft_putendl_fd`, `ft_putnbr_fd`

**Part 3 — Linked list**

The `t_list` node stores a `void *content` and a pointer to the `next` node.

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`,
  `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Resources

- The `man` pages for each reimplemented function (for example `man strlen`,
  `man memmove`, `man strlcat`).
- *The C Programming Language* (Kernighan & Ritchie) for language fundamentals.
- The 42 Norm document for the coding standard enforced by `norminette`.

### Use of AI

AI was used as a support tool during this project for reviewing ideas,
clarifying concepts, and improving documentation. It was not used as a
replacement for understanding the implementation.

All functions were reviewed, tested, and validated with `norminette`, behaviour
checks against the system C library where applicable, and memory checks using
AddressSanitizer and malloc fault-injection for allocating functions.