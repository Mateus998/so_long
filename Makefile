# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 10:32:03 by mateferr          #+#    #+#              #
#    Updated: 2025/06/06 18:27:42 by mateferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MINILIBX = minilibx

SRC = so_long.c \
src/ft_exits.c \
src/input/input_validation.c src/input/input_val_utils.c \
src/input/input_val_utils2.c \
src/begin_game.c src/keys_ctrl.c src/window.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	$(MAKE) -C minilibx -f Makefile.mk
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Lminilibx -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx -f Makefile.mk clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all