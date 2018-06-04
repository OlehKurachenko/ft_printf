/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_buffered_putchar.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:57:17 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 10:57:18 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_H
# define FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_H

# define FT_PRINTF_BUFFER_SIZE 256

# include <unistd.h>

void			ftprt_buffer_flush();

void			ftprt_buffered_putchar(char c);

#endif
