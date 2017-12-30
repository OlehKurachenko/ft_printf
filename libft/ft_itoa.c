/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:04:31 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 16:04:33 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_itoa(int n)
{
	long long		nval;
	long long		ndig;
	size_t			len;
	char			*res;

	nval = (n > 0) ? (long long)n : (long long)n * -1;
	len = (n < 0) ? 2 : 1;
	ndig = 1;
	while (nval / ndig >= 10)
	{
		ndig *= 10;
		++len;
	}
	if (!(res = ft_strnew(len)))
		return (NULL);
	len = 0;
	if (n < 0)
		res[len++] = '-';
	while (ndig != 0)
	{
		res[len++] = '0' + nval / ndig;
		nval %= ndig;
		ndig /= 10;
	}
	return (res);
}
