/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_buffered_putchar_fd.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:57:34 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 10:57:35 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_FD_H
# define FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_FD_H

# include <unistd.h>

# define FT_FPRINTF_BUFFER_SIZE 256

void ftprt_buffer_set_fd(int new_fd);

void ftprt_buffered_putchar_fd(char c);

void ftprt_buffer_flush_fd();

#endif
