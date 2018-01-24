#include "../ft_printf.h"

char    ftprt_getupdecimal(unsigned char digit, unsigned char is_big)
{
    if (digit < 10)
        return ((char)('0' + digit));
    if (is_big)
        return ((char)('A' + digit - 10));
    return ((char)('a' + digit - 10));
}