#include "../ft_printf.h"

static size_t   count_putput_len(const unsigned int *s, long long precision,
								 size_t *num_val)
{
	static size_t   size[24] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
								3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4};
	size_t          res;

	res = 0;
	*num_val = 0;
	while (*s && (precision == -1 ||
			precision >= (long long)size[ftprt_highest_byte(*s)]))
	{
		precision -= size[ftprt_highest_byte(*s)];
		res += size[ftprt_highest_byte(*s)];
		++(*num_val);
		++s;
	}
	return (res);
}

static size_t	wstrlen(const unsigned int *s)
{
	size_t	result;

	result = 0;
	while (s[result])
		result++;
	return (result);
}

static void		put_wstring(t_printff *fl, va_list *arg, int *nptr,
						 t_putchar f_putchar)
{
	const unsigned int  *s = va_arg(*arg, unsigned int *);
	size_t              num_wchars;
	const size_t        prt_num = (s) ? count_putput_len(s,
		fl->precision, &num_wchars) : 0;
	size_t              i;

	if (!s)
		return (ftprt_put_s_byval(fl, ftprt_null_str, nptr, f_putchar));
	if (prt_num < fl->width && !(fl->flags[2]))
		ftprt_putnchar(' ', fl->width - prt_num, f_putchar);
	i = 0;
	while (i < num_wchars)
	{
		ftprt_putwchar(s[i], f_putchar);
		++i;
	}
	if (prt_num < fl->width && (fl->flags[2]))
		ftprt_putnchar(' ', fl->width - prt_num, f_putchar);
	*nptr += (prt_num > fl->width) ? prt_num : fl->width;
}

static void        put_wstring_simple(t_printff *fl,
		va_list *arg, int *nptr, t_putchar f_putchar)
{
	const unsigned int  *s = va_arg(*arg, unsigned int *);
	size_t          	len;
	size_t          	i;

	if (!s)
		return (ftprt_put_s_byval(fl, ftprt_null_str, nptr, f_putchar));
	len = (fl->precision == -1) ? wstrlen(s)
		: ft_min_size_t(wstrlen(s), (size_t)fl->precision);
	if (fl->width > len && !(fl->flags[2]))
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	i = 0;
	while (i < len)
	{
		f_putchar((char)s[i]);
		++i;
	}
	if (fl->width > len && (fl->flags[2]))
		ftprt_putnchar(' ', fl->width - len, f_putchar);
	*nptr += (fl->width > len) ? fl->width : len;
}

void			ftprt_put_ss(t_printff *fl, va_list *arg, int *nptr,
							 t_putchar f_putchar)
{
	if (MB_CUR_MAX == 4)
		put_wstring(fl, arg, nptr, f_putchar);
	else
		put_wstring_simple(fl, arg, nptr, f_putchar);
}