/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:48:22 by okurache          #+#    #+#             */
/*   Updated: 2017/12/21 18:48:25 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (dst[i] != 0 && i < dstsize)
		i++;
	len = i;
	if (i == dstsize)
		return (len + ft_strlen(src));
	while (*src != 0)
	{
		if (i + 1 < dstsize)
			dst[i] = *src;
		i++;
		src++;
	}
	if (i < dstsize)
		dst[i] = 0;
	else
		dst[dstsize - 1] = 0;
	return (i);
}
