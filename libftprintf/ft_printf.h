#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"

# include <stdarg.h>
# include <stdint.h>

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
**		-1:		not a flag
** 		28:		type not defined
** 		0..27:	"%sSpdDioOuUxXcCeEfFgGaAnbrk"
 * 				conversions
**
*/

typedef void		(*t_putchar)(char);

typedef struct	    s_printff
{
	unsigned char	flags[6];
	size_t			width;
	long long 		precision;
	int				len_flag;
	char			type;
}				    t_printff;

/*
**  TYPE MAP
*/

typedef void        (*t_type_proc)(t_printff *,va_list *, int *, t_putchar);

const size_t        g_types_n;

const t_type_proc   g_type_map[];

int 			    ft_printf(const char *format, ...);

int                 ft_va_printf(const char *format, va_list *arg, t_putchar f_putchar);

/*
**	FLAG MANAGMENT
*/

const char		    *ftprt_set_flags(t_printff *fl, const char *pos, va_list *arg);

const char          *ftprt_set_type(t_printff *fl, const char *pos);

/*
**  OUTPUT SECTION
*/

void        		ftprt_putchar(char c);

unsigned char       ftprt_highest_byte(size_t val);

size_t              ftprt_putwchar(unsigned int c, t_putchar f_putchar);

size_t              ftprt_putwchar_lim(unsigned int c, size_t *lim, t_putchar f_putchar);

void                ftprt_putnchar(char c, size_t n, t_putchar f_putchar);

void                ftprt_put_dblpercent(t_printff *fl, va_list *arg, int *nprt,
										 t_putchar f_putchar);

void        		ftprt_put_s(t_printff *fl, va_list *arg, int *nptr,
						t_putchar f_putchar);

void            	ftprt_put_ss(t_printff *fl, va_list *arg, int *nptr,
							 t_putchar f_putchar);

unsigned char       ftprt_number_len(intmax_t val, unsigned char zero_to_one);

void                ftprt_put_number(intmax_t val, size_t len, t_printff *fl,
                             t_putchar f_putchar);

void                ftprt_put_d(t_printff *fl, va_list *arg,
								int *nprt, t_putchar f_putchar);

#endif
