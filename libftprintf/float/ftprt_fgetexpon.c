/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_fgetexpon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:08:11 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:08:12 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static const size_t	g_infinite_loop_number = 1000;

/*
**	Here, flag[6] will be used to show that number is < 0
*/

static size_t		normalize_val(int *const res,
	long double *const val)
{
	size_t	i;

	*res = 0;
	while (*val >= 10l)
	{
		*val /= 10l;
		++(*res);
	}
	i = 0;
	while (*val < 1l && ++i < g_infinite_loop_number)
	{
		*val *= 10l;
		--(*res);
	}
	return (i);
}

int					ftprt_fgetexpon(t_printff *fl, long double val,
	long double *const val_normed)
{
	int		res;
	size_t	i;

	if (val != val || val == g_flt_inf)
		return (0);
	if (fl->prec == -1)
		fl->prec = 6;
	i = normalize_val(&res, &val);
	while ((val += 0.5l * ft_ldpow(0.1l, (size_t)fl->prec)) >= 10l)
	{
		val /= 10l;
		++res;
	}
	if (val_normed)
		*val_normed = val;
	return ((i == g_infinite_loop_number) ? 0 : res);
}
