/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:30:04 by okurache          #+#    #+#             */
/*   Updated: 2017/12/21 16:30:13 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*vs;
	const unsigned char	cv = (unsigned char)c;

	vs = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*vs == cv)
			return ((void *)vs);
		++vs;
	}
	return (NULL);
}
