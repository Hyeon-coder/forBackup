# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JuHyeon <ljh3900@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:46:04 by JuHyeon           #+#    #+#              #
#    Updated: 2024/11/19 13:59:58 by JuHyeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS = \
	   ft_printf.c \
	   ft_strchr.c \
	   ft_form_check.c \
	   ft_strlen.c \
	   ft_itoa_base.c \
	   ft_itoa.c \
	   ft_putchar_rt.c \
	   ft_putstr_rt.c \
	   ft_strlen.c

OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(BOBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
