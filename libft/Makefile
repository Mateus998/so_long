# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:43:10 by mateferr          #+#    #+#              #
#    Updated: 2025/04/23 15:43:10 by mateferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(wildcard **/*.c)
OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all