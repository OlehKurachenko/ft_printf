#include "../ft_printf.h"

const char      *ftprt_set_type(t_printff *const fl, const char *pos)
{
	const size_t	temp = (size_t)ft_strchr(types, *pos);

	if (temp)
		fl->type = (char)((temp - (size_t)types) / sizeof(char));
	else
	{
		if (*pos)
			ftprt_put_c_byval(fl, *pos);
		fl->type = CONV_TYPE_NUMB;
	}
	if (*pos)
		++pos;
	return (pos);
}