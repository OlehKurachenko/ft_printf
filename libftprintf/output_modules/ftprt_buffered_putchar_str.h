/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprt_buffered_putchar_str.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:57:49 by okurache          #+#    #+#             */
/*   Updated: 2018/01/30 10:57:49 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_STR_H
# define FT_PRINTF_CLION_FTPRT_BUFFERED_PUTCHAR_STR_H

# include "../../libft/libft.h"

# define FT_SPRINTF_BUFFER_SIZE 256

void ftprt_buffer_init_str();

void ftprt_buffered_putchar_str(char c);

char *ftprt_buffer_get_str();

#endif
