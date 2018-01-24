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

# endif
