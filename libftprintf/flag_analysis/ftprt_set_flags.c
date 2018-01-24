#include "../ft_printf.h"

const char	*ftprt_set_flags(t_printff *fl, const char *pos, va_list *arg)
{
	const char *const prev_pos = pos;

	if (*pos != '%')
	{
		fl->type = -1;
		return (pos);
	}
	++pos;
	pos = ftprt_set_fflags(fl, pos);
	pos = ftprt_set_fwidth(fl, pos, arg);
	pos = ftprt_set_fprecision(fl, pos, arg);
	pos = ftprt_set_flen_flag(fl, pos);
	pos = ftprt_set_type(fl, pos);
	return ((fl->type == CONV_TYPE_NUMB) ? prev_pos + 1 : pos);
}
