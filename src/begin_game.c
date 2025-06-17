/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:40:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/17 12:45:17 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_close(t_game *game)
{
	free_game(game, NULL);
	exit(0);
	return (0);
}

t_game	*create_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		if (free_map(map))
			error_exit("game allocation fail");
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
	game->map = map;
	game->window = mlx_new_window(game->init, map->width * 64, map->height * 64,
			"so_long");
	if (!game->window)
		free_game(game, "mlx_window error");
	file_to_image(game);
	render_image(game);
	mlx_hook(game->window, 17, 0, game_close, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_hook(game->window, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->init, game_loop, game);
	mlx_loop(game->init);
}
