#include "../ft_printf.h"

static size_t   count_wchar_t_len(wchar_t c)
{
	static size_t   size[24] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
			3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4};

	return (size[ftprt_highest_byte((size_t) c)]);
}

static void		put_wchar(t_printff *const fl, va_list *const arg)
{
	const wchar_t	c = va_arg(*arg, wchar_t);
	const size_t	len = count_wchar_t_len(c);

	if (len < fl->width && !(fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - len);
	ftprt_putwchar(fl, (unsigned int)c);
	if (len < fl->width && (fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - len);
	fl->count += (len > fl->width) ? len : fl->width;
}

static void        put_wchar_simple(t_printff *const fl, va_list *const arg)
{
	const wchar_t	c = va_arg(*arg, wchar_t);

	if (fl->width && !(fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - 1);
	fl->ptchr((char)c);
	if (fl->width && (fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - 1);
	fl->count += (fl->width) ? fl->width : 1;
}

void				ftprt_put_cc(t_printff *const fl, va_list *const arg) {
	if (MB_CUR_MAX == 4)
		put_wchar(fl, arg);
	else
		put_wchar_simple(fl, arg);
}
