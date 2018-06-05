/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_xnumber.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:32:09 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:32:10 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void	ftprt_put_xnumber_apo(uintmax_t val, size_t len,
	t_printff *const fl)
{
	uintmax_t	pw;
	size_t		delim_c;

	if (fl->flags[delim_c = 0])
	{
		fl->ptchr('0');
		fl->ptchr((char)((fl->type == 11) ? 'x' : 'X'));
	}
	if (fl->prec != -1 && (fl->prec > (long long)len))
		ftprt_putnchar(fl, '0', fl->prec - len);
	if (val || fl->prec != 0)
	{
		pw = 1;
		while (val / pw >= 16 && ++delim_c)
			pw *= 16;
		while (pw)
		{
			fl->ptchr(ftprt_getupdecimal((unsigned char)(val / pw),
				(unsigned char)(fl->type != 11)));
			if (delim_c && (delim_c-- % 3 == 0))
				fl->ptchr(',');
			val %= pw;
			pw /= 16;
		}
	}
}

void		ftprt_put_xnumber(uintmax_t val, size_t len, t_printff *const fl)
{
	uintmax_t	pw;

	if (fl->flags[4])
		return (ftprt_put_xnumber_apo(val, len, fl));
	if (fl->flags[0])
	{
		fl->ptchr('0');
		fl->ptchr((char)((fl->type == 11) ? 'x' : 'X'));
	}
	if (fl->prec != -1 && (fl->prec > (long long)len))
		ftprt_putnchar(fl, '0', fl->prec - len);
	if (val || fl->prec != 0)
	{
		pw = 1;
		while (val / pw >= 16)
			pw *= 16;
		while (pw)
		{
			fl->ptchr(ftprt_getupdecimal((unsigned char)(val / pw),
				(unsigned char)(fl->type != 11)));
			val %= pw;
			pw /= 16;
		}
	}
}
