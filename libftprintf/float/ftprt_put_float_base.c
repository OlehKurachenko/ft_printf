/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_put_float_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:09:57 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:09:58 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	put_afterpoint_part(long double val,
	const long double base, t_printff *const fl,
	const unsigned char is_capital)
{
	size_t				prec;

	if (fl->prec || fl->flags[0])
		fl->ptchr('.');
	if (!fl->prec)
		return ;
	prec = (size_t)fl->prec;
	val = (val - (uintmax_t)(val)) * base;
	while (prec > 0)
	{
		fl->ptchr(ftprt_getupdecimal((unsigned char)(val), is_capital));
		val = (val - (uintmax_t)(val)) * base;
		--prec;
	}
}

static void	put_prepoint_part(long double *const val,
	const long double base, t_printff *const fl,
	const unsigned char is_capital)
{
	long double			downstep;
	size_t				cnt;

	downstep = 1l;
	cnt = 1;
	while (*val / downstep >= base)
	{
		downstep *= base;
		++cnt;
	}
	while (cnt--)
	{
		fl->ptchr(ftprt_getupdecimal((unsigned char)(*val / downstep),
			is_capital));
		*val -= (uintmax_t)(*val / downstep) * downstep;
		downstep /= base;
	}
}

static void	put_prepoint_part_apo(long double *const val,
	const long double base, t_printff *const fl,
	const unsigned char is_capital)
{
	long double		downstep;
	size_t			len_i;

	downstep = 1l;
	len_i = 0;
	while (*val / downstep >= base)
	{
		downstep *= base;
		++len_i;
	}
	fl->flags[7] = 1;
	while (*val >= 1l || fl->flags[7])
	{
		fl->ptchr(ftprt_getupdecimal(*val / downstep, is_capital));
		if (len_i % 3 == 0 && len_i)
			fl->ptchr(',');
		--len_i;
		*val -= (*val / downstep) * downstep;
		downstep /= base;
		fl->flags[7] = 0;
	}
}

/*
**	Here, flag[6] will be used to show that number is < 0
*/

void		ftprt_put_float_base(long double val, const long double base,
	t_printff *const fl)
{
	const unsigned char	is_capital = (unsigned char)(fl->type == 28);

	if (fl->flags[4])
		put_prepoint_part_apo(&val, base, fl, is_capital);
	else
		put_prepoint_part(&val, base, fl, is_capital);
	put_afterpoint_part(val, base, fl, is_capital);
}
