/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_unumber.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:31:53 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:31:54 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static void		ftprt_put_unumber_apo(uintmax_t val, size_t len,
	t_printff *const fl)
{
	uintmax_t	pw;
	size_t		delim_c;

	if (fl->prec != -1 && (fl->prec > (long long)len))
		ftprt_putnchar(fl, '0', fl->prec - len);
	if (val || fl->prec != 0)
	{
		pw = 1;
		delim_c = 0;
		while (val / pw > 9 && ++delim_c)
			pw *= 10;
		while (pw)
		{
			fl->ptchr((char)('0' + val / pw));
			if (delim_c && (delim_c-- % 3 == 0))
				fl->ptchr(',');
			val %= pw;
			pw /= 10;
		}
	}
}

void			ftprt_put_unumber(uintmax_t val, size_t len,
	t_printff *const fl)
{
	uintmax_t	pw;

	if (fl->flags[4])
		return (ftprt_put_unumber_apo(val, len, fl));
	if (fl->prec != -1 && (fl->prec > (long long)len))
		ftprt_putnchar(fl, '0', fl->prec - len);
	if (val || fl->prec != 0)
	{
		pw = 1;
		while (val / pw > 9)
			pw *= 10;
		while (pw)
		{
			fl->ptchr((char)('0' + val / pw));
			val %= pw;
			pw /= 10;
		}
	}
}
