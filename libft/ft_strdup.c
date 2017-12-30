/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:53:02 by okurache          #+#    #+#             */
/*   Updated: 2017/12/21 17:53:03 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	const size_t	len = ft_strlen(s1) + 1;
	char			*res;

	res = (char *)malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	ft_memcpy((void *)res, (void *)s1, len);
	return (res);
}
