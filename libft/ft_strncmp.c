/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 11:27:59 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 11:28:00 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 == *s2 && !(*s1 == 0 && *s2 == 0) && i++ < n)
	{
		s1++;
		s2++;
	}
	if ((*s1 == 0 && *s2 == 0) || n == i)
		return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
