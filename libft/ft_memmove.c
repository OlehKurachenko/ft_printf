/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:34:22 by okurache          #+#    #+#             */
/*   Updated: 2017/11/16 19:34:29 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void	*ft_memcpy_bs(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n-- != 1)
	{
		++d;
		++s;
	}
	while ((void *)d >= dst)
		*(d--) = *(s--);
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
		ft_memcpy_bs(dst, src, len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
