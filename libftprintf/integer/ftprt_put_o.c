/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:30:50 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:30:51 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		precision_case(t_printff *const fl,
	const size_t len, const uintmax_t val)
{
	fl->flags[5] = (unsigned char)(fl->prec == -1);
	if (fl->flags[0] && val && fl->prec <= (long long)len)
		fl->prec = (long long int)(len) + 1;
	if (fl->flags[0] && (!val) && fl->prec == 0)
		fl->prec = 1;
	if (fl->prec != -1)
	{
		if (!fl->flags[5])
			fl->flags[1] = 0;
	}
	else if (fl->width > 0 && fl->flags[1])
		fl->prec = (long long int)fl->width;
}

static size_t	get_const_len(const uintmax_t val, const t_printff *const fl)
{
	return (ftprt_ublen(val, ((fl->prec != 0) ? 1 : fl->flags[0]),
		fl->flags[4], 8));
}

/*
**	Here, fl.flag[5] is special flag shows was there a presicion in call
*/

void			ftprt_put_o(t_printff *const fl, va_list *const arg)
{
	const uintmax_t	val = ftprt_va_get_uvalue(fl, arg);
	const size_t	len = get_const_len(val, fl);
	size_t			used_len;

	precision_case(fl, len, val);
	used_len = (fl->prec == -1 || len >
		(long long unsigned)fl->prec) ? len : (size_t)fl->prec;
	if (used_len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, (char)((fl->flags[1]) ? '0' : ' '),
			fl->width - used_len);
	ftprt_put_onumber(val, len, fl);
	if (used_len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - used_len);
	fl->count += ft_max_size_t(fl->width, used_len);
}
