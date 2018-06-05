/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_unumber_baselen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:32:20 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:32:21 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

unsigned char	ftprt_ublen(uintmax_t val, unsigned char zero_to_one,
	unsigned char is_apo, unsigned char base)
{
	unsigned char	res;

	if (val == 0)
		return (zero_to_one);
	res = 0;
	while (val != 0)
	{
		++res;
		val /= base;
	}
	if (is_apo)
		return ((unsigned char)(res + (res - 1) / 3));
	return (res);
}
