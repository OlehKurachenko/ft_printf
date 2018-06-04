/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_buffered_putchar_str.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:57:42 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 10:57:42 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprt_buffered_putchar_str.h"

static char		*g_buff = 0;
static char		*g_temp_buff;
static size_t	g_buff_s;
static size_t	g_buff_i;

char	*ftprt_buffer_get_str(void)
{
	char	*res;

	if (!g_buff)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (g_buff_i + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, g_buff, g_buff_i);
	res[g_buff_i] = 0;
	free(g_buff);
	return (res);
}

void	ftprt_buffered_putchar_str(char c)
{
	if (!g_buff)
		return ;
	if (g_buff_i == g_buff_s)
	{
		g_temp_buff = (char *)malloc(sizeof(char) * g_buff_s * 2);
		if (!g_temp_buff)
			return ;
		ft_memcpy(g_temp_buff, g_buff, sizeof(char) * g_buff_s);
		g_buff_s <<= 1;
		free(g_buff);
		g_buff = g_temp_buff;
	}
	g_buff[g_buff_i++] = c;
}

void	ftprt_buffer_init_str(void)
{
	g_buff = (char *)malloc(sizeof(char) * FT_SPRINTF_BUFFER_SIZE);
	if (!g_buff)
		return ;
	g_buff_s = FT_SPRINTF_BUFFER_SIZE;
	g_buff_i = 0;
}
