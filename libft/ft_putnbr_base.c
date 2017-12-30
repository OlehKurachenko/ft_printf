/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:31:41 by okurache          #+#    #+#             */
/*   Updated: 2017/12/27 19:31:43 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, unsigned char base)
{
	long long		nval;
	long long		ndig;

	nval = (n > 0) ? (long long)n : (long long)n * -1;
	ndig = 1;
	while (nval / ndig >= base)
		ndig *= base;
	if (n < 0)
		ft_putchar('-');
	while (ndig != 0)
	{
		ft_putchar(ft_longdigit(nval / ndig));
		nval %= ndig;
		ndig /= base;
	}
}
