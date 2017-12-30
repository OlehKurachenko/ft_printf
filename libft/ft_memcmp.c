/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:48:32 by okurache          #+#    #+#             */
/*   Updated: 2017/12/21 16:48:34 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *vs1 = (const unsigned char *)s1;
	const unsigned char *vs2 = (const unsigned char *)s2;

	while (n-- > 0)
	{
		if (*vs1 != *vs2)
			return (*vs1 - *vs2);
		++vs1;
		++vs2;
	}
	return (0);
}
