#include "ft_printf.h"

unsigned char       ftprt_number_len(intmax_t val, unsigned char zero_to_one)
{
	unsigned char   res;

	if (val == 0)
		return (zero_to_one);
	res = 0;
	while (val != 0)
	{
		++res;
		val /= 10;
	}
	return (res);
}