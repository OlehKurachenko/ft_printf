#include "../ft_printf.h"

static const size_t 	infinite_loop_number = 1000;

static size_t			normalize_val(t_printff *const fl, int *const res,
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
	while ((*val += 0.5l * ft_ldpow(1l / 16l, (size_t)fl->precision)) >= 16l)
	{
		*val /= 2l;
		++(*res);
	}
	return (i);
}

static size_t			normalize_val_sh(t_printff *const fl, int *const res,
									   long double *const val)
{
	size_t	i;

	*res = 0;
	while (*val >= 2l)
	{
		*val /= 2l;
		++(*res);
	}
	i = 0;
	while (*val < 1l && ++i < infinite_loop_number)
	{
		*val *= 2l;
		--(*res);
	}
	while ((*val += 0.5l * ft_ldpow(1l / 16l, (size_t)fl->precision)) >= 2l)
	{
		*val /= 2l;
		++(*res);
	}
	return (i);
}

int 					ftprt_agetexpon(t_printff *const fl,
	long double val, long double *const n_form)
{
	int		res;
	size_t	i;

	if (val != val || val == flt_inf)
		return (0);
	i = (fl->type == 6) ? normalize_val(fl, &res, &val)
		: normalize_val_sh(fl, &res, &val);
	if (n_form)
		*n_form = val;
	return ((i == infinite_loop_number) ? 0 : res);
}