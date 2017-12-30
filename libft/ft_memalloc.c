/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 12:20:22 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 12:20:25 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char *)malloc(size);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		res[i] = 0;
	return (void *)res;
}
