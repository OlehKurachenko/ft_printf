/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_buffered_putchar_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:57:29 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 10:57:30 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprt_buffered_putchar_fd.h"

static char		g_buff[FT_FPRINTF_BUFFER_SIZE];
static size_t	g_buff_i = 0;
static int		g_fd;

void	ftprt_buffer_flush_fd(void)
{
	if (g_buff_i)
		write(g_fd, g_buff, g_buff_i);
	g_buff_i = 0;
}

void	ftprt_buffered_putchar_fd(char c)
{
	g_buff[g_buff_i++] = c;
	if (g_buff_i == FT_FPRINTF_BUFFER_SIZE)
		ftprt_buffer_flush_fd();
}

void	ftprt_buffer_set_fd(int new_fd)
{
	g_fd = new_fd;
}
