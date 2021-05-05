# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 14:53:22 by kcraster          #+#    #+#              #
#    Updated: 2021/03/02 17:56:02 by kcraster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

#CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c 				\
		parsing.c   				\
		int_processing.c			\
		processing.c				\
		string_char_processing.c	\
		hex_processing.c			\
		percent_processing.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT): 
	(cd libft; make all)

$(NAME): $(OBJS) $(LIBFT)
	ar rc $(NAME) $(OBJS)

$(OBJS): %.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)
	(cd libft; make clean)

fclean: clean
	rm -f $(NAME)
	(cd libft; make fclean)

re: fclean all
