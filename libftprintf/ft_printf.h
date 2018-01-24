#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <time.h>
# include "date/time_t.h"
# include "../libft/libft.h"

# define CONV_TYPE_NUMB 30

/*
**	FLAGS:
**		0: '#' flag
**		1: '0' flag
**		2: '-' flag
**		3: ' ' flag
**		4: ''' flag
**		5: '+' flag
**
** 		6, 7: temporary operational flags
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
** 		0..27:	"%sSpdDioOu UxXcCeEfFn kKbBrRGgAa"
** 				conversions
**
*/

typedef void		(*const t_putchar)(char);

typedef struct	    s_printff
{
	unsigned char	flags[8];
	size_t			width;
	long long 		precision;
	int				len_flag;
	char			type;
	short unsigned	arg;
}				    t_printff;

/*
**  TYPE MAP
*/

typedef void        (*t_type_proc)(t_printff *,va_list *, int *, t_putchar);

static const char   types[CONV_TYPE_NUMB + 1]
	= "%sSpdDioOuUxXcCeEfFnkKbBrRGgAa";

const t_type_proc   g_type_map[CONV_TYPE_NUMB];

int 			    ft_printf(const char *format, ...);

int					ft_fprintf(const int fd, const char *format, ...);

int					ft_sprintf(const char **const str, const char *format, ...);

unsigned char		ordered_chech(const char *fstr);

int                 ft_va_printf(const char *format, va_list *arg, t_putchar f_putchar);

int     			ft_va_printf_ordered(const char *format,
	va_list *arg, t_putchar f_putchar);

/*
**	FLAG MANAGMENT
*/

const char			*ftprt_set_fflags(t_printff *fl, const char *pos);

const char			*ftprt_set_fwidth(t_printff *fl, const char *pos, va_list *arg);

const char			*ftprt_set_flen_flag(t_printff *fl, const char *pos);

const char   		*ftprt_set_fprecision(t_printff *fl, const char *pos,
										  va_list *arg);

const char		    *ftprt_set_flags(t_printff *fl, const char *pos, va_list *arg);

const char			*ftprt_set_flags_ordered(t_printff *fl, const char *pos, va_list *arg);

const char          *ftprt_set_type(t_printff *fl, const char *pos);

/*
**  OUTPUT SECTION
*/

static const long double	flt_inf = 1.0/0.0;

static const char			ftprt_null_str[] = "(null)";

void				ftprt_putstr(char const *s, t_putchar f_putchar);

unsigned char       ftprt_highest_byte(size_t val);

size_t              ftprt_putwchar(unsigned int c, t_putchar f_putchar);

void                ftprt_putnchar(char c, size_t n, t_putchar f_putchar);

void                ftprt_put_dblpercent(t_printff *fl, va_list *arg, int *nprt,
										 t_putchar f_putchar);

void        		ftprt_put_s(t_printff *fl, va_list *arg, int *nptr,
						t_putchar f_putchar);

void				ftprt_put_s_byval(t_printff *const fl, const char *s, int *const nptr,
						  t_putchar f_putchar);

void            	ftprt_put_ss(t_printff *fl, va_list *arg, int *nptr,
							 t_putchar f_putchar);

unsigned char       ftprt_number_len(intmax_t val, unsigned char zero_to_one,
									 unsigned char is_apo);
void                ftprt_put_number(intmax_t val, size_t len, t_printff *fl,
							 t_putchar f_putchar);

void                ftprt_put_d(t_printff *fl, va_list *arg,
								int *nprt, t_putchar f_putchar);

void        		ftprt_put_dd(t_printff *fl, va_list *arg,
						 int *nprt, t_putchar f_putchar);

uintmax_t           ftprt_va_get_uvalue(t_printff *fl, va_list *arg);

unsigned char       ftprt_unumber_len(uintmax_t val, unsigned char zero_to_one,
									  unsigned char is_apo);

void        		ftprt_put_unumber(uintmax_t val, size_t len, t_printff *fl,
							  t_putchar f_putchar);

void                ftprt_put_u(t_printff *fl, va_list *arg,
						int *nprt, t_putchar f_putchar);

void                ftprt_put_uu(t_printff *fl, va_list *arg,
						 int *nprt, t_putchar f_putchar);

char                ftprt_getupdecimal(unsigned char digit, unsigned char is_big);

unsigned char       ftprt_unumber_baselen(uintmax_t val, unsigned char zero_to_one,
	 unsigned char is_apo, unsigned char base);

void                ftprt_put_xnumber(uintmax_t val, size_t len,
										  t_printff *fl, t_putchar f_putchar);

void                ftprt_put_x(t_printff *fl, va_list *arg,
						int *nprt, t_putchar f_putchar);

void    			ftprt_put_p(t_printff *fl, va_list *arg,
					int *nprt, t_putchar f_putchar);

void				ftprt_put_onumber(uintmax_t val, size_t len,
										  t_printff *fl, t_putchar f_putchar);

void				ftprt_put_o(t_printff *fl, va_list *arg, int *nptr,
						t_putchar f_putchar);

void				ftprt_put_oo(t_printff *fl, va_list *arg, int *nprt,
						 t_putchar f_putchar);

void				ftprt_put_c(t_printff *fl, va_list *arg, int *nprt,
						t_putchar f_putchar);

void				ftprt_put_cc(t_printff *fl, va_list *arg,
								 int *nprt, t_putchar f_putchar);

long double			ftprt_va_get_fvalue(t_printff *fl, va_list *arg);

int		ftprt_fgetexpon(t_printff *fl, long double val,
						   const long double base, long double *const val_normed);

void				ftprt_put_e(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar);

void				ftprt_put_float_base(long double val, const long double base,
	t_printff *const fl, t_putchar f_putchar);

void				ftprt_put_unumber_smpl(uintmax_t val, t_putchar f_putchar);

void				ftprt_put_f(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar);

unsigned char		ftprt_handle_nans(t_printff *fl,
	const long double val, int *nptr, t_putchar f_putchar);

void				ftprt_put_sign(t_printff *const fl, t_putchar f_putchar);

long double			ftprt_set_fsign(t_printff *const fl, long double val);

void				ftprt_put_n(t_printff *fl, va_list *arg,
								int *nprt, t_putchar f_putchar);

void				ftprt_put_k(t_printff *fl, va_list *arg,
								int *nprt, t_putchar f_putchar);

void				ftprt_put_kk(t_printff *fl, va_list *arg,
								 int *nprt, t_putchar f_putchar);

void				ftprt_put_b(t_printff *fl, va_list *arg,
								int *nprt, t_putchar f_putchar);

void				ftprt_put_bb(t_printff *fl, va_list *arg,
								 int *nprt, t_putchar f_putchar);

void				ftprt_put_r(t_printff *fl, va_list *arg,
								int *nprt, t_putchar f_putchar);

void				ftprt_put_f_byvalue(t_printff *const fl,
	const long double val, int *const nprt, t_putchar f_putchar);

void				ftprt_put_e_byvalue(t_printff *const fl,
	const long double val, int *const nprt, t_putchar f_putchar);

void				ftprt_put_g(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar);

void				ftprt_put_a(t_printff *fl, va_list *arg,
	int *nptr, t_putchar f_putchar);

#endif
