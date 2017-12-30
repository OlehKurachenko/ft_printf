/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:49:22 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 16:49:23 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long		nval;
	long long		ndig;

	nval = (n > 0) ? (long long)n : (long long)n * -1;
	ndig = 1;
	while (nval / ndig >= 10)
		ndig *= 10;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (ndig != 0)
	{
		ft_putchar_fd('0' + nval / ndig, fd);
		nval %= ndig;
		ndig /= 10;
	}
}
