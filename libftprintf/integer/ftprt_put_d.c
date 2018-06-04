/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:30:23 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:30:26 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static intmax_t		get_value(t_printff *fl, va_list *arg)
{
	if (fl->len_flag == 0)
		return (va_arg(*arg, long long));
	if (fl->len_flag == 1)
		return (va_arg(*arg, long));
	if (fl->len_flag == 2)
		return ((signed char)(va_arg(*arg, int)));
	if (fl->len_flag == 3)
		return ((short int)(va_arg(*arg, int)));
	if (fl->len_flag == 4)
		return (va_arg(*arg, intmax_t));
	if (fl->len_flag == 5)
		return (va_arg(*arg, ssize_t));
	return (va_arg(*arg, int));
}

/*
**  Flag fl->flags[0] is auto-set by 0, and than used as
**  width-to-precision delegation flag
*/

void				ftprt_put_d(t_printff *const fl, va_list *const arg)
{
	const intmax_t		val = get_value(fl, arg);
	const size_t		len = ftprt_nlen(val, fl->prec != 0, fl->flags[4]);
	size_t				used_len;

	if (fl->prec != -1)
		fl->flags[1] = 0;
	else if (fl->width > 0 && fl->flags[1])
		fl->prec = (long long int)(fl->width - (val < 0 || fl->flags[3]
			|| fl->flags[5]));
	used_len = (fl->prec == -1 || len > (long long unsigned)fl->prec)
		? len : (size_t)fl->prec;
	if (val < 0 || fl->flags[3] || fl->flags[5])
		++used_len;
	if (used_len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '),
			fl->width - used_len);
	ftprt_put_number(val, len, fl);
	if (used_len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - used_len);
	fl->count += ft_max_size_t(fl->width, used_len);
}
