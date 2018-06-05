/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:51:19 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 15:51:20 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_t.h"

static int		g_z;
static int		g_era;
static unsigned	g_doe;
static unsigned g_yoe;
static unsigned g_doy;
static unsigned g_mp;

void			destruct_t_time_t(const t_time_t **const ptr_t_time_t)
{
	free((void *)*ptr_t_time_t);
	*ptr_t_time_t = 0;
}

void			destruct_const_t_time_t(const t_time_t *const ptr_t_time_t)
{
	free((void *)ptr_t_time_t);
}

t_time_t		*construct_t_time_t_uf(const time_t unix_time_s)
{
	t_time_t *const	res = (t_time_t *)malloc(sizeof(t_time_t));

	res->second = (unsigned int)(unix_time_s % 60);
	res->minute = (unsigned int)((unix_time_s / 60) % 60);
	res->hour = (unsigned int)((unix_time_s / 3600) % 24);
	g_z = (int)(unix_time_s / 86400 + 719468);
	g_era = (g_z >= 0 ? g_z : g_z - 146096) / 146097;
	g_doe = (unsigned)(g_z - g_era * 146097);
	g_yoe = (g_doe - g_doe / 1460 + g_doe / 36524 - g_doe / 146096) / 365;
	res->year = g_yoe + g_era * 400;
	g_doy = g_doe - (365 * g_yoe + g_yoe / 4 - g_yoe / 100);
	g_mp = (5 * g_doy + 2) / 153;
	res->day = g_doy - (153 * g_mp + 2) / 5 + 1;
	res->month = g_mp + (g_mp < 10 ? 3 : -9);
	res->year += (res->month <= 2);
	return (res);
}
