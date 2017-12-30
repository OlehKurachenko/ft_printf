/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:31:52 by okurache          #+#    #+#             */
/*   Updated: 2017/12/29 15:32:00 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstfree_in(t_list **alst)
{
	t_list *temp;

	if (alst && *alst)
	{
		temp = (*alst)->next;
		if ((*alst)->c)
			free((*alst)->c);
		free(*alst);
		*alst = temp;
	}
}
