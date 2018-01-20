#include "../ft_printf.h"

static void ftprt_put_unumber_apo(uintmax_t val, size_t len, t_printff *fl,
                                 t_putchar f_putchar)
{
    uintmax_t   pw;
    size_t      delim_c;

    if (fl->precision != -1 && (fl->precision > len))
        ftprt_putnchar('0', fl->precision - len, f_putchar);
    if (val || fl->precision != 0)
    {
        pw = 1;
        delim_c = 0;
        while (val / pw > 9 && ++delim_c)
            pw *= 10;
        while (pw)
        {
            f_putchar((char)('0' + val / pw));
            if (delim_c && (delim_c-- % 3 == 0))
                f_putchar(',');
            val %= pw;
            pw /= 10;
        }
    }
}

void        ftprt_put_unumber(uintmax_t val, size_t len, t_printff *fl,
							 t_putchar f_putchar)
{
	uintmax_t pw;

    if (fl->flags[4])
        return (ftprt_put_unumber_apo(val, len, fl, f_putchar));
	if (fl->precision != -1 && (fl->precision > len))
		ftprt_putnchar('0', fl->precision - len, f_putchar);
	if (val || fl->precision != 0)
	{
		pw = 1;
		while (val / pw > 9)
			pw *= 10;
		while (pw)
		{
			f_putchar((char)('0' + val / pw));
			val %= pw;
			pw /= 10;
		}
	}
}