#include "ft_printf.h"

const char      *ftprt_set_type(t_printff *fl, const char *pos)
{
	static const char   types[28] = "%sSpdDioOuUxXcCeEfFgGaAnbrk";

	fl->type = (char)(ft_strchr(types, *pos) - types);
	++pos;
	return (pos);
}