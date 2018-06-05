/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_nlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:30:07 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:30:08 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

unsigned char	ftprt_nlen(intmax_t val, unsigned char zero_to_one,
	unsigned char is_apo)
{
	unsigned char	res;

	if (val == 0)
		return (zero_to_one);
	res = 0;
	while (val != 0)
	{
		++res;
		val /= 10;
	}
	if (is_apo)
		return ((unsigned char)(res + (res - 1) / 3));
	return (res);
}
