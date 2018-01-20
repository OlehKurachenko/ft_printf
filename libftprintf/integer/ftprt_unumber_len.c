#include "../ft_printf.h"

unsigned char       ftprt_unumber_len(uintmax_t val, unsigned char zero_to_one,
                                     unsigned char is_apo)
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
    if (is_apo)
        return ((unsigned char)(res + (res - 1) / 3));
	return (res);
}