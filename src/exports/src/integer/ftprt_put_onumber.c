/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_onumber.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:30:57 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:30:58 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static const size_t	g_ftprt_base = 8;

static void			ftprt_put_onumber_apo(uintmax_t val, size_t len,
	t_printff *const fl)
{
	uintmax_t	pw;
	size_t		delim_c;

	if (fl->prec != -1 && ((long long unsigned)fl->prec > len))
		ftprt_putnchar(fl, '0', fl->prec - len);
	if (val || fl->prec != 0)
	{
		pw = 1;
		delim_c = 0;
		while (val / pw >= g_ftprt_base && ++delim_c)
			pw *= g_ftprt_base;
		while (pw)
		{
			fl->ptchr((char)('0' + val / pw));
			if (delim_c && (delim_c-- % 3 == 0))
				fl->ptchr(',');
			val %= pw;
			pw /= g_ftprt_base;
		}
	}
}

void				ftprt_put_onumber(uintmax_t val, size_t len,
	t_printff *const fl)
{
	uintmax_t	pw;

	if (fl->flags[4])
		return (ftprt_put_onumber_apo(val, len, fl));
	if (fl->prec != -1 && ((long long unsigned)fl->prec > len))
		ftprt_putnchar(fl, '0', fl->prec - len);
	if (val || fl->prec != 0)
	{
		pw = 1;
		while (val / pw >= g_ftprt_base)
			pw *= g_ftprt_base;
		while (pw)
		{
			fl->ptchr((char)('0' + val / pw));
			val %= pw;
			pw /= g_ftprt_base;
		}
	}
}
