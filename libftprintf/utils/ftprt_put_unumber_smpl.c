#include "../ft_printf.h"

void	ftprt_put_unumber_smpl(t_printff *const fl, uintmax_t val)
{
	uintmax_t pw;

	pw = 1;
	while (val / pw > 9)
		pw *= 10;
	while (pw)
	{
		fl->ptchr((char)('0' + val / pw));
		val %= pw;
		pw /= 10;
	}
}