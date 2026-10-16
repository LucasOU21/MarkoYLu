*This project has been created as part of the 42 curriculum by [mmitrovi].*

# Libft

## Description

`Libft` is the first individual project in the 42 curriculum. Its primary goal is to re-create a selection of standard C library functions (`libc`), along with additional utility functions for memory management, string manipulation, and linked list handling. 

Building a custom C library provides a deep, foundational understanding of pointer arithmetic, dynamic memory allocation (`malloc`, `free`), data structure implementation, and low-level system behaviors in C. The resulting static library (`libft.a`) serves as a foundational dependency for future 42 projects.

---

## Library Overview & Function Descriptions

The library consists of mandatory functions modeled after `libc`, custom utility functions, and bonus linked list management functions.

### 1. Standard Libc Functions

* **Memory Management:**
  * `ft_memset` – Fills memory with a constant byte.
  * `ft_bzero` – Erases data in a memory area by writing zeros.
  * `ft_memcpy` – Copies a memory block from source to destination.
  * `ft_memmove` – Safely copies memory even when source and destination overlap.
  * `ft_memchr` – Searches memory for a specific character.
  * `ft_memcmp` – Compares two memory blocks byte-by-byte.
  * `ft_calloc` – Allocates memory for an array and initializes all bytes to zero.

* **String Manipulation:**
  * `ft_strlen` – Measures the length of a string.
  * `ft_strlcpy` – Copies a string to a buffer with size handling.
  * `ft_strlcat` – Appends a string to another with size bounds checking.
  * `ft_strchr` – Finds the first occurrence of a character in a string.
  * `ft_strrchr` – Finds the last occurrence of a character in a string.
  * `ft_strncmp` – Compares two strings up to $n$ bytes.
  * `ft_strnstr` – Locates a substring within a string up to a maximum length.
  * `ft_strdup` – Allocates and duplicates a string.

* **Character Tests & Conversion:**
  * `ft_isalpha` – Checks if a character is alphabetic.
  * `ft_isdigit` – Checks if a character is a decimal digit ($0$ through $9$).
  * `ft_isalnum` – Checks if a character is alphanumeric.
  * `ft_isascii` – Checks if a character is an ASCII character.
  * `ft_isprint` – Checks if a character is printable.
  * `ft_toupper` – Converts a character to uppercase.
  * `ft_tolower` – Converts a character to lowercase.
  * `ft_atoi` – Converts an ASCII string to an integer.

### 2. Additional Utility Functions

* `ft_substr` – Extracts a substring from a given string.
* `ft_strjoin` – Concatenates two strings into a new dynamically allocated string.
* `ft_strtrim` – Trims specified trailing and leading characters from a string.
* `ft_split` – Splits a string into an array of substrings using a specified delimiter.
* `ft_itoa` – Converts an integer into a dynamically allocated ASCII string.
* `ft_strmapi` – Applies a function to each character of a string to build a new string.
* `ft_striteri` – Applies a function in-place to each character of a string.
* `ft_putchar_fd` – Writes a single character to a specific file descriptor.
* `ft_putstr_fd` – Writes a string to a specific file descriptor.
* `ft_putendl_fd` - Writes a string followed by a newline to a file descriptor.
* `ft_putnbr_fd` – Writes an integer to a specific file descriptor.

### 3. Bonus Functions (Linked Lists)

Functions designed to manipulate single-linked list structures (`t_list`):

* `ft_lstnew` – Allocates and initializes a new list element.
* `ft_lstadd_front` – Adds an element at the beginning of the list.
* `ft_lstsize` – Counts the total number of elements in the list.
* `ft_lstlast` – Returns the last element of the list.
* `ft_lstadd_back` – Adds an element at the end of the list.
* `ft_lstdelone` – Deletes a single element and frees its memory using a custom function.
* `ft_lstclear` – Deletes and frees an entire list.
* `ft_lstiter` – Iterates through a list and applies a function to the content of each element.
* `ft_lstmap` – Creates a new list by applying a function to each element of an existing list.

---

## Instructions

### Compilation

The project uses a standard `Makefile` compiled with `gcc` and the `-Wall -Wextra -Werror` flags.

1. **Build mandatory library:**
   ```bash
   make
   ```
   This generates the static library file `libft.a`.

2. **Build with bonus functions:**
   ```bash
   make bonus
   ```

3. **Clean object files:**
   ```bash
   make clean
   ```

4. **Clean object files and `libft.a`:**
   ```bash
   make fclean
   ```

5. **Recompile everything from scratch:**
   ```bash
   make re
   ```

### Integration & Execution

To use `libft.a` in another C program:

1. Include the header in your C file:
   ```c
   #include "libft.h"
   ```
2. Compile your program linking the `libft.a` binary:
   ```bash
   gcc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

---

## Resources

### References & Documentation
* [Man7 Linux Manual Pages](https://man7.org/linux/man-pages/) – Standard reference for standard C library functions (`string.h`, `stdlib.h`, `ctype.h`).
* [GeeksforGeeks C Programming](https://www.geeksforgeeks.org/c-programming-language/) – Explanations of dynamic memory allocation and linked list structures.
* 42 Subject PDF – Specific rules and function prototypes.

### AI Disclosure

* **Tasks:** AI was used exclusively for creating, formatting, and structuring this `README.md` file according to the mandatory 42 template requirements.
* **Parts of the project:** All C code files (`*.c`), header files (`*.h`), and the build system (`Makefile`) were written manually without AI code generation.