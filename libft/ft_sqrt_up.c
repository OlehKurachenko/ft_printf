/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:21:33 by okurache          #+#    #+#             */
/*   Updated: 2017/12/25 20:21:34 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sqr(int nb)
{
	return (nb * nb);
}

int			ft_sqrt_up(int nb)
{
	int prediction;
	int step;

	if (nb < 1 || nb > 2147395600)
		return (0);
	prediction = 23170;
	step = prediction / 2;
	while (1)
	{
		if (ft_sqr(prediction) == nb)
			return (prediction);
		if (ft_sqr(prediction) < nb && ft_sqr(prediction + 1) > nb)
			return (prediction + 1);
		if (ft_sqr(prediction) > nb)
			prediction -= step;
		else
			prediction += step;
		step = step / 2;
		if (step == 0)
			step = 1;
	}
}
