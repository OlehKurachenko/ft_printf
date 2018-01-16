#include "libft.h"

long double		ft_ldpow(long double val, size_t pow)
{
	long double		res;

	res = 1l;
	while (pow)
	{
		if (pow & 1)
		{
			res *= val;
		}
		val *= val;
		pow >>= 1;
	}
	return (res);
}