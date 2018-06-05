/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_t.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:51:26 by okurache          #+#    #+#             */
/*   Updated: 2018/01/28 15:51:28 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CLION_TIME_T_H
# define FT_PRINTF_CLION_TIME_T_H

# include <stdint.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_time_t
{
	unsigned	year;
	unsigned	month;
	unsigned	day;
	unsigned	hour;
	unsigned	minute;
	unsigned	second;
}				t_time_t;

t_time_t		*construct_t_time_t_uf(const time_t unix_time_s);

void			destruct_t_time_t(const t_time_t **const ptr_t_time_t);

void			destruct_const_t_time_t(const t_time_t *const ptr_t_time_t);

#endif
