//
// Created by Oleh KURACHENKO on 12/30/17.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdarg.h>

// TODO write code comments

/*
**	FLAGS:
**		0: '#' flag
**		1: '0' flag
**		2: '-' flag
**		3: ' ' flag
**		4: ''' flag
**		5: '+' flag
**
**	TYPE:
**		0: not a flag
**
*/

typedef struct	s_printff
{
	unsigned char	flags[6];
	size_t			width;
	long long 		precision;
	int				len_flag;
	unsigned char	type;
}				t_printff;

int 			ft_printf(const char *format, ...);

/*
**	FLAG MANAGMENT
*/

const char		*ftprt_set_flags(t_printff *fl, const char *pos);

/*
**  OUTPUT SECTION
*/

unsigned char   ftprt_highest_byte(size_t val);

size_t      ft_putwchar(unsigned int c);

size_t      ft_putwchar_lim(unsigned int c, size_t *lim);

#endif
