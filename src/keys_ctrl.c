/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:40:10 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 11:10:31 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_control(t_game *game, int event, int y, int x, char m)
{
	if (game->map->map[game->map->playery][game->map->playerx] == 'G')
		game->map->map[game->map->playery][game->map->playerx] = 'E';
	else
		game->map->map[game->map->playery][game->map->playerx] = '0';
	if (m == 'w')
		game->map->map[y][x] = 'W';
	else if (m == 'a')
		game->map->map[y][x] = 'A';
	else if (m == 's')
		game->map->map[y][x] = 'P';
	else if (m == 'd')
		game->map->map[y][x] = 'D';
	if (event == 1)
	{
		game->map->collect--;
		if (!game->map->collect)
			game->map->map[game->map->exity][game->map->exitx] = 'F';
	}
	else if (event == 2)
		game->map->map[y][x] = 'G';
	else if (event == 3)
		game_close(game);
}

void	move(t_game *game, int y, int x, char m)
{
	int			event;
	static int	moves;

	event = 0;
	if (game->map->map[y][x] == '1')
		return ;
	else if (game->map->map[y][x] == 'C')
		event = 1;
	else if (game->map->map[y][x] == 'E')
		event = 2;
	else if (game->map->map[y][x] == 'F')
		event = 3;
	move_control(game, event, y, x, m);
	moves++;
	ft_printf("%i\n", moves);
	game->map->playery = y;
	game->map->playerx = x;
	render_image(game);
}

int	key_loop(void *param)
{
	t_game		*game;
	static int	delay;

	game = (t_game *)param;
	delay++;
	if (delay >= 7000)
	{
		if (game->key_w)
			move(game, game->map->playery - 1, game->map->playerx, 'w');
		else if (game->key_a)
			move(game, game->map->playery, game->map->playerx - 1, 'a');
		else if (game->key_s)
			move(game, game->map->playery + 1, game->map->playerx, 's');
		else if (game->key_d)
			move(game, game->map->playery, game->map->playerx + 1, 'd');
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
