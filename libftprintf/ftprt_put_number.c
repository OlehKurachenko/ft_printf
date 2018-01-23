#include "ft_printf.h"

static void ftprt_put_number_apo(intmax_t val, size_t len, t_printff *fl,
                                 t_putchar f_p)
{
    uintmax_t   temp;
    uintmax_t   pw;
    size_t      delim_c;

    if ((fl->flags[3] || fl->flags[5]) && val >= 0)
        f_p((char) ((fl->flags[3]) ? ' ' : '+'));
    if (val < 0)
        f_p('-');
    if (fl->precision != -1 && ((long long unsigned)fl->precision > len))
        ftprt_putnchar('0', fl->precision - len, f_p);
    if ((temp = (uintmax_t)((val >= 0) ? val : -val)) || fl->precision != 0)
    {
        pw = 1;
        delim_c = 0;
        while (temp / pw > 9 && ++delim_c)
            pw *= 10;
        while (pw)
        {
            f_p((char)('0' + temp / pw));
            if (delim_c && (delim_c-- % 3 == 0))
                f_p(',');
            temp %= pw;
            pw /= 10;
        }
    }
}

void        ftprt_put_number(intmax_t val, size_t len, t_printff *fl,
							 t_putchar f_putchar)
{
	uintmax_t temp;
	uintmax_t pw;

    if (fl->flags[4])
        return (ftprt_put_number_apo(val, len, fl, f_putchar));
	if ((fl->flags[3] || fl->flags[5]) && val >= 0)
		f_putchar((char) ((fl->flags[3]) ? ' ' : '+'));
	if (val < 0)
		f_putchar('-');
	if (fl->precision != -1 && ((long long unsigned)fl->precision > len))
        ftprt_putnchar('0', fl->precision - len, f_putchar);
	if ((temp = (uintmax_t)((val >= 0) ? val : -val)) || fl->precision != 0)
	{
		pw = 1;
		while (temp / pw > 9)
			pw *= 10;
		while (pw)
		{
			f_putchar((char)('0' + temp / pw));
			temp %= pw;
			pw /= 10;
		}
	}
}