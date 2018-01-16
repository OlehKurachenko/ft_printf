#include "ft_printf.h"

static const long long		e_type_deft_precision = 6;
static const long double	e_type_base = 10l;

static size_t 				count_length(t_printff *const fl, long double val)
{
	size_t	res;

	res = 1;
	if (fl->precision == -1)
		fl->precision = e_type_deft_precision;
	if (val < 0 || fl->flags[3] || fl->flags[5])
		++res;
	if (fl->precision || fl->flags[0])
		++res;
	val /= e_type_base;
	while (val >= e_type_base)
	{
		val /= e_type_base;
		++res;
	}
	// TODO isapo
	return (res + fl->precision);
}

void						ftprt_put_f(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar)
{
	const long double	val = ftprt_va_get_fvalue(fl, arg);
	const size_t 		len = count_length(fl, val);


	// TODO write
}