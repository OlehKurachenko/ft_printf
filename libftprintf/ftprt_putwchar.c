#include "ft_printf.h"

static void put_2_char_wchar(unsigned int c)
{
	ft_putchar((char)((3 << 6) ^ (c >> 6)));
	ft_putchar((char)((1 << 7) ^ (c & ((1 << 6) - 1))));
}

static void put_3_char_wchar(unsigned int c)
{
	ft_putchar((char)((7 << 5) ^ (c >> 12)));
	ft_putchar((char)((1 << 7) ^ ((c >> 6) & ((1 << 6) - 1))));
	ft_putchar((char)((1 << 7) ^ (c & ((1 << 6) - 1))));
}

static void put_4_char_wchar(unsigned int c)
{
	ft_putchar((char)((15 << 4) ^ (c >> 18)));
	ft_putchar((char)((1 << 7) ^ ((c >> 12) & ((1 << 6) - 1))));
	ft_putchar((char)((1 << 7) ^ ((c >> 6) & ((1 << 6) - 1))));
	ft_putchar((char)((1 << 7) ^ (c & ((1 << 6) - 1))));
}

size_t      ft_putwchar(unsigned int c)
{
	const unsigned char hb = ftprt_highest_byte(c);

	if (hb <= 7)
	{
		ft_putchar((char)c);
		return (1);
	}
	if (hb <= 11)
	{
		put_2_char_wchar(c);
		return (2);
	}
	if (hb <= 16)
	{
		put_3_char_wchar(c);
		return (3);
	}
	put_4_char_wchar(c);
	return (4);
}

size_t      ft_putwchar_lim(unsigned int c, size_t *lim)
{
	const unsigned char hb = ftprt_highest_byte(c);

	if (*lim >= 1 && hb <= 7)
	{
		ft_putchar((char)c);
		return (1);
	}
	if (*lim >= 2 && hb <= 11)
	{
		put_2_char_wchar(c);
		return (2);
	}
	if (*lim >= 3 && hb <= 16)
	{
		put_3_char_wchar(c);
		return (3);
	}
	if (*lim >= 4)
	{
		put_4_char_wchar(c);
		return (4);
	}
	return (*lim = 0);
}