/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:31:21 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/13 17:12:18 by mateferr         ###   ########.fr       */
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

void	file_to_image_player(t_game *game, int w, int h)
{
	game->win->portal_p = mlx_xpm_file_to_image(game->init,
			"assets/portal_player.xpm", &w, &h);
	game->win->player_w = mlx_xpm_file_to_image(game->init, "assets/up.xpm", &w,
			&h);
	game->win->player_a = mlx_xpm_file_to_image(game->init, "assets/left.xpm",
			&w, &h);
	game->win->player_s = mlx_xpm_file_to_image(game->init, "assets/down.xpm",
			&w, &h);
	game->win->player_d = mlx_xpm_file_to_image(game->init, "assets/right.xpm",
			&w, &h);
	if (!game->win->player_w || !game->win->player_a || !game->win->player_d
		|| !game->win->player_s || !game->win->portal_p)
		free_game(game, "images not correctly loaded");
}

void	sprite_animation(t_game *game)
{
	static t_list	*portal_on;
	static t_list	*portal_off;

	if (!game->map->collect)
	{
		if (!portal_on)
			portal_on = game->anim->potal_on;
		mlx_put_image_to_window(game->init, game->window, portal_on->content,
			game->map->exitx * 64, game->map->exity * 64);
		portal_on = portal_on->next;
	}
	else
	{
		if (!portal_off)
			portal_off = game->anim->portal_off;
		mlx_put_image_to_window(game->init, game->window, portal_off->content,
			game->map->exitx * 64, game->map->exity * 64);
		portal_off = portal_off->next;
	}
	enemy_animation(game);
}

void	enemy_animation(t_game *game)
{
	static t_list	*enemy;
	int				x;
	int				y;

	if (!enemy)
		enemy = game->anim->enemy;
	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'e')
				mlx_put_image_to_window(game->init, game->window,
					enemy->content, x * 64, y * 64);
			x++;
		}
		y++;
	}
	enemy = enemy->next;
}

void	free_anim(t_game *game, t_list **anim)
{
	t_list	*next_node;
	t_list	*node;

	if (anim != NULL)
	{
		node = *anim;
		while (node != NULL)
		{
			next_node = node->next;
			mlx_destroy_image(game->init, node->content);
			free(node);
			node = next_node;
		}
		*anim = NULL;
	}
}
