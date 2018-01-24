#include "../ft_printf.h"

unsigned char   ftprt_highest_byte(size_t val)
{
	unsigned char   res;

	res = 0;
	while (val)
	{
		++res;
		val >>= 1;
	}
	return (res);
}