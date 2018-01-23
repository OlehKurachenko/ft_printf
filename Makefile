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

SRC_N = ftprt_highest_byte.c \
		ftprt_number_len.c \
		ftprt_put_number.c \
		ftprt_put_d.c \
		ftprt_put_dd.c \
		ftprt_put_u.c \
		ftprt_va_get_uvalue.c \
		ftprt_put_unumber.c \
		ftprt_unumber_len.c \
		ftprt_put_uu.c \
		ftprt_unumber_baselen.c \
		ftprt_put_x.c \
		ftprt_put_xnumber.c \
		ftprt_put_p.c \
		ftprt_put_o.c \
		ftprt_put_onumber.c \
		ftprt_put_oo.c \
		ftprt_put_unumber_smpl.c \
		ftprt_putwchar.c \
		ftprt_put_dblpercent.c \
		ftprt_put_s.c \
		ftprt_putnchar.c \
		ftprt_put_ss.c \
		ftprt_put_c.c \
		ftprt_put_cc.c \
		ftprt_put_e.c \
		ftprt_va_get_fvalue.c \
		ftprt_fgetexpon.c \
		ftprt_put_float_base.c \
		ftprt_put_f.c \
		ftprt_handle_nans.c \
		ftprt_put_sign.c \
		ftprt_set_fsign.c \
		ftprt_put_g.c \
		ftprt_put_a.c \
		ftprt_getupdecimal.c \
		ftprt_putstr.c \
		ftprt_put_b.c \
		ftprt_put_bb.c \
		ftprt_put_r.c \
		ftprt_put_k.c \
		ftprt_put_kk.c \
		time_t.c \
		ftprt_set_flags.c \
		ftprt_set_type.c \
		ftprt_set_flags_ordered.c \
		ftprt_set_fflags.c \
		ftprt_set_fwidth.c \
		ftprt_set_flen_flag.c \
		ftprt_set_fprecision.c \
		ftprt_buffered_putchar.c \
		ftprt_buffered_putchar_fd.c \
		ftprt_buffered_putchar_str.c \
		ft_printf.c \
		ft_va_printf.c \
		ftprt_put_n.c \
		ftprt_ordered_check.c \
		ft_va_printf_ordered.c \
		ft_fprintf.c \
		ft_sprintf.c

SRC = $(addprefix libftprintf/, $(SRC_N))

OBJ = $(SRC:.c=.o)

LIBS = libft/libft.a

all: $(NAME)

libftprintf/%.o : libftprintf/%.c
	$(CC) -c $< -o $@

$(NAME): liball $(OBJ)
	$(LC) $(NAME) $(LIBS) $(OBJ)

clean: libclean
	rm -f libftprintf/*.o

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