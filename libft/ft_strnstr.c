/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 10:58:07 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 10:58:09 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	size_str = ft_min_size_t(ft_strlen(haystack), len);
	const size_t	size_to_find = ft_strlen(needle);
	size_t			i;

	i = 0;
	if (size_str < size_to_find)
		return (NULL);
	if (len < size_to_find)
		return (NULL);
	while (i <= size_str - size_to_find)
		if (ft_strnequ(haystack + i, needle, size_to_find))
			return ((char *)haystack + i);
		else
			i++;
	return (NULL);
}
