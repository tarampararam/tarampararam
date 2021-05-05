# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcraster <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/07 16:21:30 by kcraster          #+#    #+#              #
#    Updated: 2020/11/09 13:15:17 by kcraster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_isprint.c 	\
		ft_putendl_fd.c	\
		ft_strlen.c		\
		ft_itoa.c		\
		ft_putnbr_fd.c	\
		ft_strmapi.c	\
		ft_atoi.c		\
		ft_memccpy.c	\
		ft_putstr_fd.c	\
		ft_strncmp.c	\
		ft_bzero.c		\
		ft_memchr.c		\
		ft_split.c		\
		ft_strnstr.c	\
		ft_calloc.c		\
		ft_memcmp.c		\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_isalnum.c	\
		ft_memcpy.c		\
		ft_strdup.c		\
		ft_strtrim.c	\
		ft_isalpha.c	\
		ft_memmove.c	\
		ft_strjoin.c 	\
		ft_substr.c  	\
		ft_isascii.c 	\
		ft_memset.c  	\
		ft_strlcat.c 	\
		ft_tolower.c    \
		ft_isdigit.c    \
		ft_putchar_fd.c \
		ft_strlcpy.c    \
		ft_toupper.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) : %.o : %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
