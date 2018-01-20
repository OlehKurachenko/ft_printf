#include "../ft_printf.h"

uintmax_t    ftprt_va_get_uvalue(t_printff *fl, va_list *arg)
{
    if (fl->len_flag == 0)
        return (va_arg(*arg, unsigned long long));
    if (fl->len_flag == 1)
        return (va_arg(*arg, unsigned long));
    if (fl->len_flag == 2)
        return ((unsigned char)(va_arg(*arg, unsigned)));
    if (fl->len_flag == 3)
        return ((short unsigned)(va_arg(*arg, unsigned)));
    if (fl->len_flag == 4)
        return (va_arg(*arg, uintmax_t));
    if (fl->len_flag == 5)
        return (va_arg(*arg, size_t));
    return (va_arg(*arg, unsigned));
}