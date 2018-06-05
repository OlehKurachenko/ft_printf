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

SRC_DIR = src

OBJ_DIR = obj

SRC_N = integer/ftprt_highest_byte.c \
		integer/ftprt_nlen.c \
		integer/ftprt_put_number.c \
		integer/ftprt_put_d.c \
		integer/ftprt_put_dd.c \
		integer/ftprt_put_u.c \
		integer/ftprt_va_get_uvalue.c \
		integer/ftprt_put_unumber.c \
		integer/ftprt_ulen.c \
		integer/ftprt_put_uu.c \
		integer/ftprt_ublen.c \
		integer/ftprt_put_x.c \
		integer/ftprt_put_xnumber.c \
		integer/ftprt_put_p.c \
		integer/ftprt_put_o.c \
		integer/ftprt_put_onumber.c \
		integer/ftprt_put_oo.c \
		character/ftprt_putwchar.c \
		character/ftprt_put_dblpercent.c \
		character/ftprt_put_s.c \
		character/ftprt_put_s_byval.c \
		character/ftprt_put_ss.c \
		character/ftprt_put_c.c \
		character/ftprt_put_cc.c \
		character/ftprt_put_c_byval.c \
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
		float/ftprt_agetexpon.c \
		utils/ftprt_getupdecimal.c \
		utils/ftprt_putstr.c \
		utils/ftprt_put_unumber_smpl.c \
		utils/ftprt_putnchar.c \
		binary/ftprt_put_b.c \
		binary/ftprt_put_bb.c \
		binary/ftprt_put_r.c \
		date/ftprt_put_k.c \
		date/ftprt_put_kk.c \
		date/time_t.c \
		flag_analysis/ftprt_set_flags.c \
		flag_analysis/ftprt_set_type.c \
		flag_analysis/ftprt_set_flags_ordered.c \
		flag_analysis/ftprt_set_fflags.c \
		flag_analysis/ftprt_set_fwidth.c \
		flag_analysis/ftprt_set_flen_flag.c \
		flag_analysis/ftprt_set_fprecision.c \
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

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_N:.c=.o))

IMPORTS_PATH = ../../imports

LIBFT_PATH = $(IMPORTS_PATH)/okurache_libft

LIBFT_A = libft.a

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/integer
	mkdir -p $(OBJ_DIR)/character
	mkdir -p $(OBJ_DIR)/float
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/binary
	mkdir -p $(OBJ_DIR)/date
	mkdir -p $(OBJ_DIR)/flag_analysis
	mkdir -p $(OBJ_DIR)/output_modules

$(NAME): $(LIBFT_PATH)/$(LIBFT_A) $(OBJ_DIR) $(OBJ)
	cp $(LIBFT_PATH)/libft.a libftprintf.a
	ar -q libftprintf.a $(OBJ)

clean: libclean
	rm -rf $(OBJ_DIR)

fclean: clean libfclean
	rm -f $(NAME)

re: fclean all

$(LIBFT_PATH)/$(LIBFT_A):
	@make -C $(LIBFT_PATH)/ all

libclean:
	@make -C $(LIBFT_PATH)/ clean

libfclean:
	@make -C $(LIBFT_PATH)/ fclean

libre:
	@make -C $(LIBFT_PATH)/ re