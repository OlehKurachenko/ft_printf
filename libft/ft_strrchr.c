/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:11:19 by okurache          #+#    #+#             */
/*   Updated: 2017/12/21 19:11:20 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char		*vs;
	const char	cc = (char)c;
	char		*prev;

	prev = NULL;
	vs = (char *)s;
	while (*vs != 0)
	{
		if (*vs == cc)
			prev = vs;
		++vs;
	}
	return ((cc == 0) ? vs : prev);
}
