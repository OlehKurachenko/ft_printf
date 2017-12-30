/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 19:56:46 by okurache          #+#    #+#             */
/*   Updated: 2017/12/29 19:56:48 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char		*res;

	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	ft_memcpy((void *)res, (void *)s1, n);
	res[n] = 0;
	return (res);
}
