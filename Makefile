# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/04 17:48:55 by hlriabts          #+#    #+#              #
#    Updated: 2018/02/13 21:04:36 by hlriabts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = lem-in.c hash.c alg.c pre_alg.c hash_find.c

OBJ = $(SRC:.c=.o)

MAKELIB = make -C libftprintf/

LIBPATH = libftprintf/libftprintf.a

SFLAG = -c -Wall -Werror -Wextra -O3 -Os

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(LIBPATH) $(OBJ)
	gcc -o $(NAME)  $(OBJ) $(LIBPATH) 

$(LIBPATH): 
	make -C libftprintf/

%.o: %.c
	gcc $(SFLAG)  $< -o $@ 

clean: 
	rm -f $(OBJ)
	make -C libftprintf/ clean

fclean: clean
	rm -f $(NAME)
	make -C libftprintf/ fclean

re: fclean all

