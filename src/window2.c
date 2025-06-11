/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:31:21 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:04:17 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image_player(t_game *game, int y, int x)
{
	if (game->map->map[y][x] == 'G')
		mlx_put_image_to_window(game->init, game->window, game->win->portal_p, x
			* 64, y * 64);
	else if (game->map->map[y][x] == 'P')
		mlx_put_image_to_window(game->init, game->window, game->win->player_s, x
			* 64, y * 64);
	else if (game->map->map[y][x] == 'W')
		mlx_put_image_to_window(game->init, game->window, game->win->player_w, x
			* 64, y * 64);
	else if (game->map->map[y][x] == 'A')
		mlx_put_image_to_window(game->init, game->window, game->win->player_a, x
			* 64, y * 64);
	else if (game->map->map[y][x] == 'D')
		mlx_put_image_to_window(game->init, game->window, game->win->player_d, x
			* 64, y * 64);
}

void	file_to_image_player(t_game *game)
{
	int		w;
	int		h;
	t_win	*win;

	win = game->win;
	win->portal_p = mlx_xpm_file_to_image(game->init,
			"assets/portal_player.xpm", &w, &h);
	win->player_w = mlx_xpm_file_to_image(game->init, "assets/up.xpm", &w, &h);
	win->player_a = mlx_xpm_file_to_image(game->init, "assets/left.xpm", &w,
			&h);
	win->player_s = mlx_xpm_file_to_image(game->init, "assets/down.xpm", &w,
			&h);
	win->player_d = mlx_xpm_file_to_image(game->init, "assets/right.xpm", &w,
			&h);
	if (!win->collect || !win->floor || !win->player_s || !win->portal_off
		|| !win->portal_on || !win->portal_p || !win->wall || !win->player_a
		|| !win->player_d || !win->player_w)
		if (free_game(game))
			error_exit("images not correctly loaded");
}
