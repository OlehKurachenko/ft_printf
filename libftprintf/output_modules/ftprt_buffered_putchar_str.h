#ifndef FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_STR_H
# define FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_STR_H

# include "../../libft/libft.h"

# define FT_SPRINTF_BUFFER_SIZE 256

void ftprt_buffer_init_str();

void ftprt_buffered_putchar_str(char c);

char *ftprt_buffer_get_str();

#endif
