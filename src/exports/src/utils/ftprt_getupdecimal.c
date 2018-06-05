/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_getupdecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:03:12 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 11:03:12 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	ftprt_getupdecimal(unsigned char digit, unsigned char is_big)
{
	if (digit < 10)
		return ((char)('0' + digit));
	if (is_big)
		return ((char)('A' + digit - 10));
	return ((char)('a' + digit - 10));
}
