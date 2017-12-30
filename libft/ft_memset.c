/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:45:18 by okurache          #+#    #+#             */
/*   Updated: 2017/10/27 22:03:28 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc;
	unsigned char	val;
	size_t			i;

	i = 0;
	val = (unsigned char)c;
	uc = (unsigned char *)b;
	while (i < len)
	{
		uc[i] = val;
		++i;
	}
	return (b);
}
