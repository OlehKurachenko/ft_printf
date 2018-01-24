#include "../ft_printf.h"

/*
** fl->len_flag used as temporary variable
*/
const char	*ftprt_set_fwidth(t_printff *fl, const char *pos, va_list *arg)
{
	fl->width = 0;
	if (*pos == '*')
	{
		fl->len_flag = va_arg(*arg, int);
		if (fl->len_flag < 0)
		{
			fl->flags[1] = 0;
			fl->flags[2] = 1;
			fl->width = (size_t)-fl->len_flag;
		}
		else
			fl->width = (size_t)fl->len_flag;
		return (pos + 1);
	}
	while (ft_isdigit(*pos))
	{
		fl->width *= 10;
		fl->width += *pos - '0';
		++pos;
	}
	return (pos);
}