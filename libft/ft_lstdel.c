/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:14:31 by okurache          #+#    #+#             */
/*   Updated: 2017/12/23 17:14:32 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;

	if (!alst)
		return ;
	if (*alst)
	{
		node = *alst;
		while (node)
		{
			*alst = node->next;
			ft_lstdelone(&node, del);
			node = *alst;
		}
	}
	*alst = NULL;
}
