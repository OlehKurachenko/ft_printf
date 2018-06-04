/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_buffered_putchar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:57:11 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 10:57:12 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprt_buffered_putchar.h"

static char		g_buff[FT_PRINTF_BUFFER_SIZE];
static size_t	g_buff_i = 0;

void	ftprt_buffered_putchar(char c)
{
	g_buff[g_buff_i++] = c;
	if (g_buff_i == FT_PRINTF_BUFFER_SIZE || c == '\n')
		ftprt_buffer_flush();
}

void	ftprt_buffer_flush(void)
{
	if (g_buff_i)
		write(1, g_buff, g_buff_i);
	g_buff_i = 0;
}
