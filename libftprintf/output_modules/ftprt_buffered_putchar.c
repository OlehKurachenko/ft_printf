#include "ftprt_buffered_putchar.h"

static char		buff[FT_PRINTF_BUFFER_SIZE];
static size_t	buff_i = 0;

void ftprt_buffered_putchar(char c) {
	buff[buff_i++] = c;
	if (buff_i == FT_PRINTF_BUFFER_SIZE)
		ftprt_buffer_flush();
}

void ftprt_buffer_flush() {
	if (buff_i)
		write(1, buff, buff_i);
	buff_i = 0;
}
