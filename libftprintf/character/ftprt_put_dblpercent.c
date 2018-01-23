#include "../ft_printf.h"

void        ftprt_put_dblpercent(t_printff *fl, va_list *arg, int *nprt,
                                 t_putchar f_putchar)
{
    f_putchar('%');
    ++(*nprt);
}