# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arojas-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 18:46:47 by arojas-r          #+#    #+#              #
#    Updated: 2024/10/14 18:46:54 by arojas-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_printf.c \
		ft_others.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	
all: $(NAME)

.PHONY: all clean fclean re 

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
