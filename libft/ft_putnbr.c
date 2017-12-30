/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:31:10 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 16:31:12 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long		nval;
	long long		ndig;

	nval = (n > 0) ? (long long)n : (long long)n * -1;
	ndig = 1;
	while (nval / ndig >= 10)
		ndig *= 10;
	if (n < 0)
		ft_putchar('-');
	while (ndig != 0)
	{
		ft_putchar('0' + nval / ndig);
		nval %= ndig;
		ndig /= 10;
	}
}
