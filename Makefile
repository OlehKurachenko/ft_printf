# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okurache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 19:59:59 by okurache          #+#    #+#              #
#    Updated: 2018/01/23 20:00:01 by okurache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

LC = ar rc

SRC_N = integer/ftprt_highest_byte.c \
		integer/ftprt_number_len.c \
		integer/ftprt_put_number.c \
		integer/ftprt_put_d.c \
		integer/ftprt_put_dd.c \
		integer/ftprt_put_u.c \
		integer/ftprt_va_get_uvalue.c \
		integer/ftprt_put_unumber.c \
		integer/ftprt_unumber_len.c \
		integer/ftprt_put_uu.c \
		integer/ftprt_unumber_baselen.c \
		integer/ftprt_put_x.c \
		integer/ftprt_put_xnumber.c \
		integer/ftprt_put_p.c \
		integer/ftprt_put_o.c \
		integer/ftprt_put_onumber.c \
		integer/ftprt_put_oo.c \
		integer/ftprt_put_unumber_smpl.c \
		character/ftprt_putwchar.c \
		character/ftprt_put_dblpercent.c \
		character/ftprt_put_s.c \
		character/ftprt_putnchar.c \
		character/ftprt_put_ss.c \
		character/ftprt_put_c.c \
		character/ftprt_put_cc.c \
		float/ftprt_put_e.c \
		float/ftprt_va_get_fvalue.c \
		float/ftprt_fgetexpon.c \
		float/ftprt_put_float_base.c \
		float/ftprt_put_f.c \
		float/ftprt_handle_nans.c \
		float/ftprt_put_sign.c \
		float/ftprt_set_fsign.c \
		float/ftprt_put_g.c \
		float/ftprt_put_a.c \
		utils/ftprt_getupdecimal.c \
		utils/ftprt_putstr.c \
		binary/ftprt_put_b.c \
		binary/ftprt_put_bb.c \
		binary/ftprt_put_r.c \
		date/ftprt_put_k.c \
		date/ftprt_put_kk.c \
		time_t/time_t.c \
		flags_analysis/ftprt_set_flags.c \
		flags_analysis/ftprt_set_type.c \
		flags_analysis/ftprt_set_flags_ordered.c \
		flags_analysis/ftprt_set_fflags.c \
		flags_analysis/ftprt_set_fwidth.c \
		flags_analysis/ftprt_set_flen_flag.c \
		flags_analysis/ftprt_set_fprecision.c \
		output_modules/ftprt_buffered_putchar.c \
		output_modules/ftprt_buffered_putchar_fd.c \
		output_modules/ftprt_buffered_putchar_str.c \
		ft_printf.c \
		ft_va_printf.c \
		ftprt_put_n.c \
		ftprt_ordered_check.c \
		ft_va_printf_ordered.c \
		ft_fprintf.c \
		ft_sprintf.c

SRC = $(addprefix libftprintf/, $(SRC_N))

OBJ_N = $(SRC_N:.c=.o)

OBJ = $(addprefix libftprintf/obj/, $(OBJ_N))

LIBS = libft/libft.a

all: $(NAME)

libftprintf/obj/%.o : libftprintf/%.c
	$(CC) -c $< -o $@

$(NAME): liball $(OBJ)
	$(LC) $(NAME) $(OBJ)

clean: libclean
	rm -rf libftprintf/obj

fclean: clean libfclean
	rm -f $(NAME)

re: fclean all

liball:
	@make -C libft/ all

libclean:
	@make -C libft/ clean

libfclean:
	@make -C libft/ fclean

libre:
	@make -C libft/ re