#include "../ft_printf.h"

static const size_t	infinite_loop_number = 1000;

/*
**	Here, flag[6] will be used to show that number is < 0
*/

static size_t		normalize_val(int *const res, const long double base,
	long double *const val)
{
	size_t	i;

	*res = 0;
	while (*val >= base)
	{
		*val /= base;
		++(*res);
	}
	i = 0;
	while (*val < 1l && ++i < infinite_loop_number)
	{
		*val *= base;
		--(*res);
	}
	return (i);
}

int					ftprt_fgetexpon(t_printff *fl, long double val,
	const long double base, long double *const val_normed)
{
	int		res;
	size_t	i;

	if (fl->precision == -1)
		fl->precision = 6;
	if (val != val || val == flt_inf)
		return (0);
	i = normalize_val(&res, base, &val);
	while ((val += 0.5l * ft_ldpow(1l / base, (size_t)fl->precision)) >= base)
	{
		val /= base;
		++res;
	}
	if (val_normed)
		*val_normed = val;
	return ((i == infinite_loop_number) ? 0 : res);
}