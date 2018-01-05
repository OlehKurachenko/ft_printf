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
**  WIDTH:
**      number from 0 to +inf
**
**  PRECISION:
**      number from 0 to +inf if exist
**      number = -1 if no precision
**
**	LEN FLAG:
**		NULL:	-1
**		ll:		0
**		l:		1
**		hh: 	2
**		h:		3
**		j:		4
**		z:		5
**		L:		6
**
**	TYPE:
**		-1: not a flag
** 		0: type not defined
** 		"%sSpdDioOuUxXcCeEfFgGaAnbrk": conversions
**
*/

typedef struct	s_printff
{
	unsigned char	flags[6];
	size_t			width;
	long long 		precision;
	int				len_flag;
	char			type;
}				t_printff;

int 			ft_printf(const char *format, ...);

/*
**	FLAG MANAGMENT
*/

const char		*ftprt_set_flags(t_printff *fl, const char *pos);

const char      *ftprt_set_type(t_printff *fl, const char *pos);

/*
**  OUTPUT SECTION
*/

unsigned char   ftprt_highest_byte(size_t val);

size_t      ft_putwchar(unsigned int c);

size_t      ft_putwchar_lim(unsigned int c, size_t *lim);

#endif
