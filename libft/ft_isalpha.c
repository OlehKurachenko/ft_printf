/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 11:37:35 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 11:37:44 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	const unsigned char	cc = (unsigned char)c;

	if (c != (int)cc)
		return (0);
	return ((cc >= 'A' && cc <= 'Z') || (cc >= 'a' && cc <= 'z'));
}
