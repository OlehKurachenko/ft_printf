/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:34:54 by okurache          #+#    #+#             */
/*   Updated: 2017/11/07 17:35:03 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*sc;

	sc = (unsigned char *)s;
	while (n-- != 0)
	{
		*sc = 0;
		sc++;
	}
}
