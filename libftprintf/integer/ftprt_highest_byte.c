/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_highest_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:29:36 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 16:29:37 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned char	ftprt_highest_byte(size_t val)
{
	unsigned char	res;

	res = 0;
	while (val)
	{
		++res;
		val >>= 1;
	}
	return (res);
}
