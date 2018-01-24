#include "../ft_printf.h"

const char      *ftprt_set_type(t_printff *fl, const char *pos)
{
	const size_t	temp = (size_t)ft_strchr(types, *pos);

	if (temp)
		fl->type = (char)(ft_strchr(types, *pos) - types);
	else
		fl->type = CONV_TYPE_NUMB;
	++pos;
	return (pos);
}