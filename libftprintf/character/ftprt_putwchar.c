#include "../ft_printf.h"

static void put_2_char_wchar(unsigned int c, t_putchar f_putchar)
{
	f_putchar((char)((3 << 6) ^ (c >> 6)));
	f_putchar((char)((1 << 7) ^ (c & ((1 << 6) - 1))));
}

static void put_3_char_wchar(unsigned int c, t_putchar f_putchar)
{
	f_putchar((char)((7 << 5) ^ (c >> 12)));
	f_putchar((char)((1 << 7) ^ ((c >> 6) & ((1 << 6) - 1))));
	f_putchar((char)((1 << 7) ^ (c & ((1 << 6) - 1))));
}

static void put_4_char_wchar(unsigned int c, t_putchar f_putchar)
{
	f_putchar((char)((15 << 4) ^ (c >> 18)));
	f_putchar((char)((1 << 7) ^ ((c >> 12) & ((1 << 6) - 1))));
	f_putchar((char)((1 << 7) ^ ((c >> 6) & ((1 << 6) - 1))));
	f_putchar((char)((1 << 7) ^ (c & ((1 << 6) - 1))));
}

size_t      ftprt_putwchar(t_printff *const fl, unsigned int c)
{
	const unsigned char hb = ftprt_highest_byte(c);

	if (hb <= 7)
	{
		fl->ptchr((char)c);
		return (1);
	}
	if (hb <= 11)
	{
		put_2_char_wchar(c, fl->ptchr);
		return (2);
	}
	if (hb <= 16)
	{
		put_3_char_wchar(c, fl->ptchr);
		return (3);
	}
	put_4_char_wchar(c, fl->ptchr);
	return (4);
}