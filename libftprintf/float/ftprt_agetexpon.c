#include "../ft_printf.h"

static const size_t 	infinite_loop_number = 1000;

static size_t		normalize_val(int *const res,
								   long double *const val)
{
	size_t	i;

	*res = 0;
	while (*val >= 16l)
	{
		*val /= 2l;
		++(*res);
	}
	i = 0;
	while (*val < 8l && ++i < infinite_loop_number)
	{
		*val *= 2l;
		--(*res);
	}
	return (i);
}

static int 				ftprt_agetexpon(t_printff *const fl,
	long double val, long double *const n_form)
{
	int		res;
	size_t	i;

	if (val != val || val == flt_inf)
		return (0);
	i = normalize_val(&res, &val);
	while ((val += 0.5l * ft_ldpow(1l / 16l, (size_t)fl->precision)) >= 16l)
	{
		val /= 2l;
		++res;
	}
	if (n_form)
		*n_form = val;
	return ((i == infinite_loop_number) ? 0 : res);
}