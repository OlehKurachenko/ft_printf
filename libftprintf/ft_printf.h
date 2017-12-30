//
// Created by Oleh KURACHENKO on 12/30/17.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

typedef struct	s_printff
{
	unsigned char	is_ordered;
	unsigned char	flags[4];
	size_t			width;
	size_t 			precision;
	unsigned char	len_flag;
	unsigned char	type;
}				t_printff;

int 			ft_printf(const char *format, ...);

#endif
