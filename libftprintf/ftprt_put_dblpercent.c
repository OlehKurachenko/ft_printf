#include "ft_printf.h"

void        ftprt_put_dblpercent(t_printff *fl, va_list *arg, int *nprt)
{
    ft_putchar('%');
    ++(*nprt);
}