#include "../ft_printf.h"

void        ftprt_put_dblpercent(t_printff *const fl, va_list *const arg)
{
    if (fl && arg)
        fl->ptchr('%');
    ++fl->count;
}