#include "../ft_printf.h"

const char	*ftprt_set_fflags(t_printff *fl, const char *pos)
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