/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:01:02 by okurache          #+#    #+#             */
/*   Updated: 2017/12/21 19:01:09 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char		*vs;
	const char	cc = (char)c;

	vs = (char *)s;
	while (*vs != 0)
		if (*vs == cc)
			return (vs);
		else
			++vs;
	return ((cc == 0) ? vs : NULL);
}
