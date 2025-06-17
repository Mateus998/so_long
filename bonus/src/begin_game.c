/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:40:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/17 12:48:45 by mateferr         ###   ########.fr       */
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
	free_game(game, NULL);
	exit(0);
	return (0);
}

int	move_event(char **map, int y, int x)
{
	int	event;

	event = 0;
	if (map[y][x] == 'C')
		event = 1;
	else if (map[y][x] == 'F')
		event = 3;
	else if (map[y][x] == 'e')
		event = 4;
	return (event);
}

t_game	*create_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		if (free_map(map))
			error_exit("game allocation fail");
	game->anim = NULL;
	game->init = NULL;
	game->map = map;
	game->win = NULL;
	game->window = NULL;
	game->key_a = 0;
	game->key_s = 0;
	game->key_d = 0;
	game->key_w = 0;
	game->event = 0;
	return (game);
}

void	begin_game(t_map *map)
{
	t_game	*game;

	game = create_game(map);
	game->init = mlx_init();
	if (!game->init)
		free_game(game, "mlx_init error");
	game->window = mlx_new_window(game->init, map->width * 64, map->height * 64,
			"so_long");
	if (!game->window)
		free_game(game, "malx_window error");
	file_to_image(game);
	render_image(game);
	mlx_hook(game->window, 17, 0, game_close, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->init, game_loop, game);
	mlx_loop(game->init);
}
