*This project has been created as part of the 42 curriculum by sonfong.*

## Description
This project involves students to make our own implementation the standard `printf` function, which can be included in our [libft](https://github.com/lucillesmelodrame/libft) project once completed.

It aims for students to learn about and familiarise with variadic functions and how it is used in the standard `printf`.

## Instructions
To create the **libftprintf.a** library, run the command `make all / make libftprintf.a / make`.

To remove all object files (*.o) only, run the command `make clean`.

To remove **libftprintf.a** and all object files, run the command `make fclean`. 

To remove all object files and **libftprintf.a** library, then recreate the entire library again, run the command `make re`.

When testing with a `main.c` file, include the header `ft_printf.h` and compile with `cc -Wall -Werror -Wextra` and the library.  
Example:`cc -Wall -Wextra -Werror main.c libftprintf.a`.

## Resources
This function was implemented using resources such as:
* [CodeGenes](https://www.codegenes.net/blog/how-to-write-my-own-printf-in-c/) — an article that guides people on how to implement a basic version of their own `printf`/ [StackOverflow](https://stackoverflow.com/questions/3464194/how-can-i-convert-an-integer-to-a-hexadecimal-string-in-c) — randomass stackoverflow which helped with hexadecimal printing / `man` pages — to understand the concept of variadic functions.
* [Python Tutor](https://pythontutor.com/visualize.html#mode=edit) — to help with visualisation of difficult problems.
* My own peers on campus ₍₍⚞(˶>ᗜ<˶)⚟⁾⁾**#HUGEshoutout to ktiew !! ദ്ദി˙∇˙)ว**
### AI usage
AI was not used as source for solutions but only used for research for concepts and questions that could not be easily found from the resources mentioned above, and provided extra guidance.

## Details
### Algorithm & data structure
My interpretation of `ft_printf` itself is just a left-to-right scan through the format string character by character, and figuring out what to do whenever it reaches a `'%'` sign. 

`ft_printf` — opens up the variadic args with `va_start`, then hands a **pointer** to that `va_list` (`&args`) off to a helper function (`ft_extract_format`) every time it hits a `%`.

* *The use of `&` matters because if you passed the `va_list` by value instead, the helper would just get its own local copy. A `va_arg` call in there would move that copy forward, not the real one back in `ft_printf`. Since one `ft_printf` call can hit the helper multiple times (e.g. `"%s and %d"`), each call needs to pick up exactly where the last one left off, so the `va_list` has to travel by address for every read to actually count.*

`ft_extract_format` — a simple function that checks the format (the character after %) that was passed as a parameter and forwards it to its dedicated function for printing. (`ft_handlechar`, `ft_handlestr`, `ft_handlenbr`, `ft_puthexa`, `ft_putusnbr`, `ft_putptr`, `ft_handleunknown`).  

* *I have two files for my conversion functions, `ft_helpers.c` and `ft_handles.c`. ft_helpers contain modified versions of `ft_putnbr` to print out hexaptrs and unsigned ints, while `ft_handles` contain modified versions of the normal `ft_put*`.*

**Printing digits**

For `%d`/`%i`/`%u`/`%x`/`%X`, dividing by the base (10 or 16) naturally spits digits out in reverse order. To fix this, I chose to use recursion instead of using a buffer and printing the digits backwards. **Recurse on `n / base` *first*, print the current digit *after* the recursive call returns.**

**Lookup string for hex digits**

For my hexadecima conversion, each digit value just indexes straight into `"0123456789abcdef"` (or the uppercase version for `%X`). Bonus: one function handles both `%x` and `%X`, the format is passed to the function as a parameter and it checks whether it is lowercase or uppercase.

**Return value**

Real `printf` returns how many characters it printed, which you can't know ahead of time for something like `%d` (since an `int` could be 1 digit or 11). So instead of some separate counter tracking things at the top, every printing function returns how many characters *it* wrote, all the way from the innermost `write()` up through the handler, through `ft_extract_format`, and finally into `ft_printf`'s count.

**`%p` and `NULL`**

Pointers get cast to `unsigned long` and printed through the same hex logic as `%x`, since `unsigned long` matches pointer width on this platform (checked with `sizeof`, not assumed). `NULL` gets special-cased to print `"(nil)"` outright, matching what glibc actually does — printing `0` through the normal hex path would technically also give `"0x0"`, but that's just not what real `printf` prints.
