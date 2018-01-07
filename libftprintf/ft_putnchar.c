#include "ft_printf.h"

void        ft_putnchar(char c, size_t n)
{
    while (n-- > 0)
        ft_putchar(c);
}