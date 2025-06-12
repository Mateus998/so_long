/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:40:10 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/12 18:33:53 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_control(t_game *game, int y, int x, char m)
{
	if (game->map->map[game->map->playery][game->map->playerx] == 'G')
		game->map->map[game->map->playery][game->map->playerx] = 'E';
	else
		game->map->map[game->map->playery][game->map->playerx] = '0';
	game->map->map[y][x] = m;
	if (game->event == 1)
	{
		game->map->collect--;
		if (!game->map->collect)
			game->map->map[game->map->exity][game->map->exitx] = 'F';
	}
	else if (game->event == 2)
		game->map->map[y][x] = 'G';
	else if (game->event == 3 || game->event == 4)
	{
		if (game->event == 4)
			ft_printf("you lose\n");
		else
			ft_printf("you win\n");
		game_close(game);
	}
}

void	move(t_game *game, int y, int x, char m)
{
	static int	moves;
	char		*move_str;

	if (game->map->map[y][x] == '1')
		return ;
	game->event = move_event(game->map->map, y, x);
	move_control(game, y, x, m);
	render_image(game);
	game->map->playery = y;
	game->map->playerx = x;
	moves++;
	move_str = ft_itoa(moves);
	if (!move_str)
		if (free_game(game))
			error_exit("move_str allocation error");
	mlx_string_put(game->init, game->window, 10, 10, 0xFFFFFF, move_str);
	free(move_str);
}

int	key_loop(void *param)
{
	t_game		*game;
	static int	delay;

	game = (t_game *)param;
	delay++;
	if (delay >= 8000)
	{
		if (game->key_w)
			move(game, game->map->playery - 1, game->map->playerx, 'W');
		else if (game->key_a)
			move(game, game->map->playery, game->map->playerx - 1, 'A');
		else if (game->key_s)
			move(game, game->map->playery + 1, game->map->playerx, 'P');
		else if (game->key_d)
			move(game, game->map->playery, game->map->playerx + 1, 'D');
		sprite_animation(game);
		delay = 0;
	}
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == 65307)
		game_close(game);
	else if (key == 119)
		game->key_w = 1;
	else if (key == 97)
		game->key_a = 1;
	else if (key == 115)
		game->key_s = 1;
	else if (key == 100)
		game->key_d = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 119)
		game->key_w = 0;
	else if (key == 97)
		game->key_a = 0;
	else if (key == 115)
		game->key_s = 0;
	else if (key == 100)
		game->key_d = 0;
	return (0);
}
