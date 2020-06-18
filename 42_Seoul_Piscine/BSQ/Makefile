# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/17 21:06:29 by jiyyu             #+#    #+#              #
#    Updated: 2020/06/17 21:25:50 by jiyyu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = main.c parsing.c make_txt.c map_valid_check.c core.c fill.c memory.c ft_str.c
OBJ = $(SRC:.c=.o)
ARGS = 10 10 2

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

$(OBJ): headers.h

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
