/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:30:42 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:30:43 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	ftprt_put_number_apo(intmax_t val, size_t len, t_printff *const fl)
{
	uintmax_t	temp;
	uintmax_t	pw;
	size_t		delim_c;

	if ((fl->flags[3] || fl->flags[5]) && val >= 0)
		fl->ptchr((char)((fl->flags[3]) ? ' ' : '+'));
	if (val < 0)
		fl->ptchr('-');
	if (fl->prec != -1 && ((long long unsigned)fl->prec > len))
		ftprt_putnchar(fl, '0', fl->prec - len);
	if ((temp = (uintmax_t)((val >= 0) ? val : -val)) || fl->prec != 0)
	{
		pw = 1;
		delim_c = 0;
		while (temp / pw > 9 && ++delim_c)
			pw *= 10;
		while (pw)
		{
			fl->ptchr((char)('0' + temp / pw));
			if (delim_c && (delim_c-- % 3 == 0))
				fl->ptchr(',');
			temp %= pw;
			pw /= 10;
		}
	}
}

void		ftprt_put_number(intmax_t val, size_t len, t_printff *const fl)
{
	uintmax_t	temp;
	uintmax_t	pw;

	if (fl->flags[4])
		return (ftprt_put_number_apo(val, len, fl));
	if ((fl->flags[3] || fl->flags[5]) && val >= 0)
		fl->ptchr((char)((fl->flags[3]) ? ' ' : '+'));
	if (val < 0)
		fl->ptchr('-');
	if (fl->prec != -1 && ((long long unsigned)fl->prec > len))
		ftprt_putnchar(fl, '0', fl->prec - len);
	if ((temp = (uintmax_t)((val >= 0) ? val : -val)) || fl->prec != 0)
	{
		pw = 1;
		while (temp / pw > 9)
			pw *= 10;
		while (pw)
		{
			fl->ptchr((char)('0' + temp / pw));
			temp %= pw;
			pw /= 10;
		}
	}
}
