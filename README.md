# ✨ ft_printf  
🩵 A minimalist, from-scratch reimplementation of the C `printf` function.  
## 🖤 Overview  
`ft_printf` recreates the essential functionality of the standard C `printf`, built entirely without stdio. It parses format strings, handles multiple data types, and prints them using only low-level system calls. The project reflects the 42 philosophy: simplicity, precision, and strong fundamentals.  
## ⚙️ Supported Conversions  
| Format | Description |  
|--------|-------------|  
| `%c` | Character |  
| `%s` | String |  
| `%p` | Pointer address |  
| `%d` / `%i` | Signed integer |  
| `%u` | Unsigned integer |  
| `%x` | Hex (lowercase) |  
| `%X` | Hex (uppercase) |  
| `%%` | Percent sign |  
Special handling includes: `NULL` strings → `(null)` ; `NULL` pointers → `0x0` (macOS) or `(nil)` (Linux) ; correct printing of edge cases like `INT_MIN`.  
## 🧠 Technical Highlights  
🩵 **Low-Level Output** — implemented solely with `write()`, manual printing logic, and recursion.  
🩵 **Variadic Processing** — dynamic argument handling with `va_list`, `va_start`, `va_arg`, and `va_end`.  
🩵 **Modular Architecture** — every specifier lives in its own file for clarity and maintainability:  
```
ft_printf.c     → parser + dispatcher  
ft_putchar.c    → print character  
ft_putstr.c     → print string  
ft_putnbr.c     → print signed int  
ft_putuint.c    → print unsigned int  
ft_puthex.c     → print hexadecimal  
ft_putptr.c     → print pointer  
```  
🩵 **Cross-Platform Behavior** — matches system `printf` on macOS and Linux.  
## 📁 Project Structure  
```
ft_printf/  
├── ft_printf.h  
├── Makefile  
└── src/  
    ├── ft_printf.c  
    ├── ft_putchar.c  
    ├── ft_putstr.c  
    ├── ft_putptr.c  
    ├── ft_putnbr.c  
    ├── ft_putuint.c  
    └── ft_puthex.c  
```  
## 🛠 Build Instructions  
Run `make` to compile the library: `libftprintf.a`  
Use it in your program with:  
`cc main.c libftprintf.a`  
## 🧪 Example Usage  
```c
#include "ft_printf.h"
int main(void)
{
    ft_printf("Mode: %s | Level: %d | Code: %X\\n", "active", 3, 255);
    return 0;
}
```  
Output:  
`Mode: active | Level: 3 | Code: FF`  
## 🖤 Why This Project Matters  
Rebuilding `printf` requires understanding type formatting, memory representation, parsing strategies, and platform differences. It demonstrates clean code structure, reliability, and strong low-level thinking — essential strengths in systems programming, embedded development, and high-performance backend work.  
## 📩 Contact  
For collaboration, engineering discussions, or project inquiries, feel free to reach out.  
