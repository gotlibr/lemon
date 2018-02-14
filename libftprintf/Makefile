# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 08:07:02 by hlriabts          #+#    #+#              #
#    Updated: 2018/02/04 18:39:44 by hlriabts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = get_next_line.c ft_printf.c ft_printf_dec.c ft_printf_dec_2.c ft_printf_char.c ft_printf_pars.c ft_recursive_factorial.c ft_is_negative.c  ft_sqrt.c ft_count_if.c ft_lstnew.c ft_atoi.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_lstadd.c ft_lstdelone.c ft_bzero.c ft_putchar.c ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr.c ft_putnbr.c ft_itoa.c ft_strsplit.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memalloc.c ft_memccpy.c ft_strjoin.c ft_strtrim.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strsub.c ft_tolower.c ft_toupper.c

OBJ = $(SRC:.c=.o)
SFLAG = -c -Wall -Werror -Wextra -O3 -Os

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(SFLAG) $< -o $@ 

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

my: re
	gcc -Wall -Werror -Wextra -std=c99 -o test main.c $(NAME)
	./test
	make clean
