#include "ft_printf.h"

unsigned char	ordered_chech(const char *fstr)
{
	while (*fstr)
	{
		if (*fstr == '%')
		{
			++fstr;
			if (ft_isdigit(*fstr))
			{
				while (ft_isdigit(*fstr))
					++fstr;
				if (*fstr == '$')
					return (1);
			}
		}
		++fstr;
	}
	return (0);
}