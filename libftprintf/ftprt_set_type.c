#include "ft_printf.h"

const char      *ftprt_set_type(t_printff *fl, const char *pos)
{
	static const char   types[CONV_TYPE_NUMB + 1]
			= "%sSpdDioOuUxXcCeEfFnkKbBrRGg";

	fl->type = (char)(ft_strchr(types, *pos) - types);
	++pos;
	return (pos);
}