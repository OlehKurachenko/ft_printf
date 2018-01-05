#include "ft_printf.h"

const char      *ftprt_set_type(t_printff *fl, const char *pos)
{
	static const char   types[28] = "%sSpdDioOuUxXcCeEfFgGaAnbrk";

	if (ft_strchr(types, *pos) != (types + 28))
		fl->type = *pos;
	else
		fl->type = 0;
	++pos;
	return (pos);
}