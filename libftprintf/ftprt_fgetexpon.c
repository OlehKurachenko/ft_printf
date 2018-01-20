#include "ft_printf.h"

static const size_t infinite_loop_number = 100000;

/*
**	Here, flag[6] will be used to show that number is < 0
*/

int		ftprt_fgetexpon(t_printff *fl, long double val,
	const long double base, long double *const val_normed)
{
	int		res;
	size_t	i;

	if (val != val || val == flt_inf)
		return (0);
	fl->flags[6] = (unsigned char)(val < 0);
	if (val < 0)
		val = -val;
	res = 0;
	while (val >= base)
	{
		val /= base;
		++res;
	}
	i = 0;
	while (val < 1l && ++i < infinite_loop_number)
	{
		val *= base;
		--res;
	}
	if (val_normed)
		*val_normed = val;
	return ((i == infinite_loop_number) ? 0 : res);
}