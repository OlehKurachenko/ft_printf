/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sf_bin_put_longlong.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:44:42 by okurache          #+#    #+#             */
/*   Updated: 2017/12/27 19:44:43 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const size_t	g_numbits_long_long = 8 * sizeof(unsigned long long);

void				ft_sf_bin_put_longlong(unsigned long long n)
{
	size_t	i;

	i = 0;
	while (i++ < g_numbits_long_long)
	{
		ft_putchar((n & 1) + '0');
		n >>= 1;
	}
}
