#include "../ft_printf.h"

void        ftprt_putnchar(t_printff *const fl, char c, size_t n)
{
    while (n-- > 0)
        fl->ptchr(c);
}