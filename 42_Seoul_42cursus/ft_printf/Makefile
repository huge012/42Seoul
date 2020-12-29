# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyyu </var/mail/jiyyu>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 16:22:16 by jiyyu             #+#    #+#              #
#    Updated: 2020/12/28 17:04:28 by jiyyu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a
SRCS		= ./ft_printf.c ./ft_printf_utils.c\
			  ./ft_print_char.c ./ft_print_nbr.c ./ft_print_string.c
OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)


re : fclean all
