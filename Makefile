# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 10:32:03 by mateferr          #+#    #+#              #
#    Updated: 2025/06/16 18:53:56 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MINILIBX = minilibx
BONUS = so_long_bonus

SRC = so_long.c \
src/ft_exits.c \
src/input/input_validation.c src/input/input_val_utils.c \
src/input/input_val_utils2.c src/window2.c \
src/begin_game.c src/keys_ctrl.c src/window.c
OBJ = $(SRC:.c=.o)

BSRC = bonus/so_long_bonus.c \
bonus/src/ft_exits.c \
bonus/src/input/input_validation.c bonus/src/input/input_val_utils.c \
bonus/src/input/input_val_utils2.c bonus/src/window_player.c \
bonus/src/begin_game.c bonus/src/keys_ctrl.c bonus/src/window.c \
bonus/src/window_anim.c
BOBJ = $(BSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft all
	$(MAKE) -C minilibx -f Makefile.mk
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Lminilibx -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BOBJ)
	$(MAKE) -C libft all
	$(MAKE) -C minilibx -f Makefile.mk
	$(CC) $(CFLAGS) $(BOBJ) -Llibft -lft -Lminilibx -lmlx -lXext -lX11 -lm -lbsd -o $(BONUS)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx -f Makefile.mk clean
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) $(BONUS)

re: fclean all