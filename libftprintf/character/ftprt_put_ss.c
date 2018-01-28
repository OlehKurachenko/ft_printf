#include "../ft_printf.h"

static size_t   count_putput_len(const unsigned int *s, long long precision,
								 size_t *const num_val)
{
	static size_t   size[24] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
								3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4};
	size_t          res;

	res = 0;
	*num_val = 0;
	while (*s && (precision == -1 ||
			precision >= (long long)size[ftprt_highest_byte(*s)]))
	{
		if (precision != -1)
			precision -= size[ftprt_highest_byte(*s)];
		res += size[ftprt_highest_byte(*s)];
		++(*num_val);
		++s;
	}
	return (res);
}

static size_t	wstrlen(const unsigned int *const s)
{
	size_t	result;

	result = 0;
	while (s[result])
		result++;
	return (result);
}

static void		put_wstring(t_printff *const fl, va_list *const arg)
{
	const unsigned int  *s = va_arg(*arg, unsigned int *);
	size_t              num_wchars;
	const size_t        prt_num = (s) ? count_putput_len(s,
		fl->precision, &num_wchars) : 0;
	size_t              i;

	if (!s)
		return (ftprt_put_s_byval(fl, ftprt_null_str));
	if (prt_num < fl->width && !(fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '),
		fl->width - prt_num);
	i = 0;
	while (i < num_wchars)
	{
		ftprt_putwchar(fl, s[i]);
		++i;
	}
	if (prt_num < fl->width && (fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - prt_num);
	fl->count += (prt_num > fl->width) ? prt_num : fl->width;
}

static void        put_wstring_simple(t_printff *const fl, va_list *const arg)
{
	const unsigned int  *s = va_arg(*arg, unsigned int *);
	size_t          	len;
	size_t          	i;

	if (!s)
		return (ftprt_put_s_byval(fl, ftprt_null_str));
	len = (fl->precision == -1) ? wstrlen(s)
		: ft_min_size_t(wstrlen(s), (size_t)fl->precision);
	if (fl->width > len && !(fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '), fl->width - len);
	i = 0;
	while (i < len)
	{
		fl->ptchr((char)s[i]);
		++i;
	}
	if (fl->width > len && (fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += (fl->width > len) ? fl->width : len;
}

void			ftprt_put_ss(t_printff *const fl, va_list *const arg)
{
	if (MB_CUR_MAX == 4)
		put_wstring(fl, arg);
	else
		put_wstring_simple(fl, arg);
}