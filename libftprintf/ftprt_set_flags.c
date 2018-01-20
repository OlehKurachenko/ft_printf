#include "ft_printf.h"

static const char	*set_flags(t_printff *fl, const char *pos)
{
	ft_memset(fl->flags, 0, 8);
	while (*pos == ' ' || *pos == '-' || *pos == '+'
		   || *pos == '#' || *pos == '0' || *pos == '\'')
	{
		if (*pos == ' ' && !fl->flags[5])
			fl->flags[3] = 1;
		if (*pos == '0' && !fl->flags[2])
			fl->flags[1]  = 1;
		if (*pos == '+')
		{
			fl->flags[3] = 0;
			fl->flags[5] = 1;
		}
		if (*pos == '-')
		{
			fl->flags[1] = 0;
			fl->flags[2] = 1;
		}
		if (*pos == '#')
			fl->flags[0] = 1;
		if (*pos == '\'')
			fl->flags[4] = 1;
		++pos;
	}
	return (pos);
}

/*
** fl->len_flag used as temporary variable
*/
static const char	*set_width(t_printff *fl, const char *pos, va_list *arg)
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

/*
** fl->len_flag used as temporary variable
*/
static const char   *set_precision(t_printff *fl, const char *pos,
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

static const char	*set_len_flag(t_printff *fl,
										 const char *pos)
{
	if (*pos == 'l' && *(pos + 1) == 'l')
		return (pos + ((fl->len_flag = 0) + 2));
	if (*pos == 'h' && *(pos + 1) == 'h')
		return (pos + (fl->len_flag = 2));
	if (*pos == 'l')
		return (pos + (fl->len_flag = 1));
	if (*pos == 'h')
		return (pos + ((fl->len_flag = 3) - 2));
	if (*pos == 'j')
		return (pos + ((fl->len_flag = 4) - 3));
	if (*pos == 'z')
		return (pos + ((fl->len_flag = 5) - 4));
	if (*pos == 'L')
		return (pos + ((fl->len_flag = 6) - 5));
	fl->len_flag = -1;
	return (pos);
}

const char			*ftprt_set_flags(t_printff *fl, const char *pos, va_list *arg)
{
	if (*pos != '%')
	{
		fl->type = -1;
		return (pos);
	}
	++pos;
	pos = set_flags(fl, pos);
	pos = set_width(fl, pos, arg);
	pos = set_precision(fl, pos, arg);
	pos = set_len_flag(fl, pos);
	pos = ftprt_set_type(fl, pos);
	return (pos);
}