/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:40:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/12 18:34:02 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_char(char c)
{
	if (c != '0' && c != '1' && c != '\n')
	{
		if (c != 'P' && c != 'C' && c != 'E' && c != 'e')
			return (0);
	}
	return (1);
}

int	game_close(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

int	move_event(char **map, int y, int x)
{
	int	event;

	event = 0;
	if (map[y][x] == 'C')
		event = 1;
	else if (map[y][x] == 'E')
		event = 2;
	else if (map[y][x] == 'F')
		event = 3;
	else if (map[y][x] == 'e')
		event = 4;
	return (event);
}

void	begin_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		if (free_map(map))
			error_exit("game allocation fail");
	game->init = mlx_init();
	game->map = map;
	game->window = mlx_new_window(game->init, map->width * 64, map->height * 64,
			"so_long");
	file_to_image(game);
	render_image(game);
	game->key_a = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->key_w = 0;
	mlx_hook(game->window, 17, 0, game_close, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->init, key_loop, game);
	mlx_loop(game->init);
}
