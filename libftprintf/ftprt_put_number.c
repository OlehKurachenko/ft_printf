#include "ft_printf.h"

void        ftprt_put_number(intmax_t val, size_t len, t_printff *fl,
							 t_putchar f_putchar)
{
	uintmax_t temp;
	uintmax_t pw;

	if (fl->flags[3] && val >= 0)
		f_putchar(' ');
	if (fl->flags[5] && val >= 0)
		f_putchar('+');
	if (val < 0)
		f_putchar('-');
	if (fl->precision != -1 && (fl->precision > len))
		ftprt_putnchar('0', fl->precision - len, f_putchar);
	temp = (uintmax_t)((val >= 0) ? val : -val);
	if (temp || fl->precision != 0)
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