#include "../ft_printf.h"

void	ftprt_put_unumber_smpl(uintmax_t val, t_putchar f_putchar)
{
	uintmax_t pw;

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