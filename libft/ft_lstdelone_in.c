/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:26:09 by okurache          #+#    #+#             */
/*   Updated: 2017/12/29 15:26:10 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdelone_in(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && *alst)
	{
		temp = (*alst)->next;
		if ((*alst)->c)
			del((*alst)->c, (*alst)->c_size);
		free(*alst);
		*alst = temp;
	}
}
