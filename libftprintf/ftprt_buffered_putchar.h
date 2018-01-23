#ifndef FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_H
# define FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_H

# define FT_PRINTF_BUFFER_SIZE 256

#include <unistd.h>

void			ftprt_buffer_flush();

void			ftprt_buffered_putchar(char c);

#endif
