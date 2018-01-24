#include "ftprt_buffered_putchar_fd.h"

static char		buff[FT_FPRINTF_BUFFER_SIZE];
static size_t	buff_i = 0;
static int 		fd;

void ftprt_buffer_flush_fd() {
	if (buff_i)
		write(fd, buff, buff_i);
	buff_i = 0;
}

void ftprt_buffered_putchar_fd(char c) {
	buff[buff_i++] = c;
	if (buff_i == FT_FPRINTF_BUFFER_SIZE)
		ftprt_buffer_flush_fd();
}

void ftprt_buffer_set_fd(int new_fd) {
	fd = new_fd;
}
