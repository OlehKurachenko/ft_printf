/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 19:46:26 by okurache          #+#    #+#             */
/*   Updated: 2017/12/21 19:46:27 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	const size_t	size_str = ft_strlen(haystack);
	const size_t	size_to_find = ft_strlen(needle);
	size_t			i;

	i = 0;
	if (size_str < size_to_find)
		return (NULL);
	while (i <= size_str - size_to_find)
		if (ft_strnequ(haystack + i, needle, size_to_find))
			return ((char *)haystack + i);
		else
			i++;
	return (NULL);
}
