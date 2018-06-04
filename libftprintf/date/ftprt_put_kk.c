/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_kk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:51:01 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 15:51:02 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static const char *const	g_month_key[12] =
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

static void					put_time(t_printff *const fl,
	const t_time_t *const time)
{
	ftprt_putstr(fl, g_month_key[time->month - 1]);
	ftprt_putnchar(fl, ' ', (size_t)(3
		- ftprt_ulen(time->day, 1, 0)));
	ftprt_put_unumber_smpl(fl, time->day);
	fl->ptchr(' ');
	ftprt_putnchar(fl, '0', (size_t)(2
		- ftprt_ulen(time->hour, 1, 0)));
	ftprt_put_unumber_smpl(fl, time->hour);
	fl->ptchr(':');
	ftprt_putnchar(fl, '0', (size_t)(2
		- ftprt_ulen(time->minute, 1, 0)));
	ftprt_put_unumber_smpl(fl, time->minute);
}

void						ftprt_put_kk(t_printff *const fl,
	va_list *const arg)
{
	const t_time_t *const	time = construct_t_time_t_uf(va_arg(*arg, time_t));
	const size_t			len = (fl->flags[0]) ? 4 : 12;

	if (len < fl->width && (!fl->flags[2]))
		ftprt_putnchar(fl, ' ', fl->width - len);
	if (fl->flags[0])
	{
		ftprt_putnchar(fl, '0', (size_t)(4
			- ftprt_ulen(time->year, 1, 0)));
		ftprt_put_unumber_smpl(fl, time->year);
	}
	else
		put_time(fl, time);
	if (len < fl->width && fl->flags[2])
		ftprt_putnchar(fl, ' ', fl->width - len);
	destruct_const_t_time_t(time);
	fl->count += ft_max_size_t(len, fl->width);
}
