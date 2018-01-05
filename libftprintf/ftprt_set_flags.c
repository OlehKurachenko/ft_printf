#include "ft_printf.h"

// TODO remove forbidden function call
#include <stdio.h>

static const char   *set_flags(t_printff *fl, const char *pos)
{
	ft_memset(fl->flags, 0, 4);
    // TODO add flag
	while (*pos == ' ' || *pos == '-' || *pos == '+'
		   || *pos == '#' || *pos == '0' || *pos == '*')
	{
		if (*pos == ' ' && !fl->flags[2])
			fl->flags[3] = 1;
        if (*pos == '0' && !fl->flags[2])
            ;
        // TODO finish
		++pos;
	}
	return (pos);
}

const char		    *ftprt_set_flags(t_printff *fl, const char *pos)
{
	if (*pos != '%')
	{
		fl->type = 0;
		return (pos);
	}

    // TODO write

	// TEMP code
	fl->type = 0;

	printf("UNFINISHED FUNCTION CALL: ftprt_set_flags()\n");
	return (pos);
}