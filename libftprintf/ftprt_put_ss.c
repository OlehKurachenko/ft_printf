#include "ft_printf.h"

static size_t   count_putput_len(const unsigned int *s, size_t precision,
								 size_t *num_val)
{
	static size_t   size[24] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
								3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4};
	size_t          i;
	size_t          res;

	i = 0;
	res = 0;
	*num_val = 0;
	while (*s && (precision == -1 ||
			precision >= size[ftprt_highest_byte(*s)]))
	{
		precision -= size[ftprt_highest_byte(*s)];
		res += size[ftprt_highest_byte(*s)];
		++(*num_val);
		++s;
	}
	return (res);
}

void            ftprt_put_ss(t_printff *fl, va_list *arg, int *nptr,
						 t_putchar f_putchar)
{
	const unsigned int  *s = va_arg(*arg, unsigned int *);
	size_t              num_wchars;
	const size_t        prt_num = count_putput_len(s, fl->precision, &num_wchars);
	size_t              i;

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