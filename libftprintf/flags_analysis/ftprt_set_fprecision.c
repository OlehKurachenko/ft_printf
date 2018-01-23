#include "../ft_printf.h"

/*
** fl->len_flag used as temporary variable
*/
static const char   *ftprt_set_fprecision(t_printff *fl, const char *pos,
								   va_list *arg)
{
	if (*pos == '.')
	{
		fl->precision = 0;
		++pos;
		if (*pos == '*')
		{
			fl->len_flag = va_arg(*arg, int);
			if (fl->len_flag >= 0)
				fl->precision = fl->len_flag;
			else
				fl->precision = -1;
			return (pos + 1);
		}
		while (ft_isdigit(*pos))
		{
			fl->precision *= 10;
			fl->precision += *pos - '0';
			++pos;
		}
	}
	else
		fl->precision = -1;
	return (pos);
}