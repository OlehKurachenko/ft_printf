#include "ftprt_buffered_putchar_str.h"

static char		*buff = 0;
static char 	*temp_buff;
static size_t	buff_s;
static size_t	buff_i;

char *ftprt_buffer_get_str() {
	char	*res;

	if (!buff)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (buff_i + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, buff, buff_i);
	res[buff_i] = 0;
	free(buff);
	return (res);
}

void ftprt_buffered_putchar_str(char c) {
	if (!buff)
		return ;
	if (buff_i == buff_s)
	{
		temp_buff = (char *)malloc(sizeof(char) * buff_s * 2);
		if (!temp_buff)
			return ;
		ft_memcpy(temp_buff, buff, sizeof(char) * buff_s);
		buff_s <<= 1;
		free(buff);
		buff = temp_buff;
	}
	buff[buff_i++] = c;
}

void ftprt_buffer_init_str() {
	buff = (char *)malloc(sizeof(char) * FT_SPRINTF_BUFFER_SIZE);
	if (!buff)
		return ;
	buff_s = FT_SPRINTF_BUFFER_SIZE;
	buff_i = 0;
}
