/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:42:22 by okurache          #+#    #+#             */
/*   Updated: 2017/12/21 18:42:24 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t limit;

	i = 0;
	while (s1[i])
		i++;
	limit = 0;
	while (*s2 != 0 && limit++ < n)
	{
		s1[i++] = *s2;
		s2++;
	}
	s1[i] = 0;
	return (s1);
}
