#include "ft_printf.h"

void        ftprt_putnchar(char c, size_t n, t_putchar f_putchar)
{
    while (n-- > 0)
        f_putchar(c);
}