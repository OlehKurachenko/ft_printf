/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:25:02 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 16:25:03 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>

void		ft_putstr(char const *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}
