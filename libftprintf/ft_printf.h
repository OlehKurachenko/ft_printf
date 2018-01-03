//
// Created by Oleh KURACHENKO on 12/30/17.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdarg.h>

// TODO write code comments

/*
**
**
**	TYPE:
**		0: wrong flag
**/

typedef struct	s_printff
{
	unsigned char	flags[4];
	size_t			width;
	size_t 			precision;
	unsigned char	len_flag;
	unsigned char	type;
}				t_printff;

int 			ft_printf(const char *format, ...);

const char		*ftprt_set_flags(t_printff *fl, const char *pos);

#endif
