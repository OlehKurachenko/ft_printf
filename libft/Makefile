# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okurache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 19:57:52 by okurache          #+#    #+#              #
#    Updated: 2017/11/07 18:09:15 by okurache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	version:	1.2.2 (for get_next_line)

NAME = libft.a

CC = gcc -Wall -Wextra -Werror

LC = ar rc

SRC =	ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstnew_ncp.c \
		ft_lstdelone.c \
		ft_lstdelone_in.c \
		ft_lstfree_in.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_min_size_t.c \
		ft_min_int.c \
		ft_min_uint.c \
		ft_max_size_t.c \
		ft_max_int.c \
		ft_max_uint.c \
		ft_strdlen.c \
		ft_strdnlen.c \
		ft_strndup.c \
		ft_sqrt.c \
		ft_sqrt_up.c \
		ft_longdigit.c \
		ft_putnbr_base.c \
		ft_sf_bin_put_longlong.c \
		ft_ldpow.c


OBJ = $(SRC:.c=.o)

INCL_H = lib.h

all: $(NAME)

%.o : %.c
	$(CC) -c $<

$(NAME): $(OBJ)
	$(LC) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
