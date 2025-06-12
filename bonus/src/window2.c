/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:31:21 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/12 18:33:39 by mateferr         ###   ########.fr       */
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
	game->anim = NULL;
	file_to_image_anim(game, w, h, "assets/up.xpm");
	file_to_image_anim(game, w, h, "assets/right.xpm");
	file_to_image_anim(game, w, h, "assets/down.xpm");
	file_to_image_anim(game, w, h, "assets/left.xpm");
}

void	file_to_image_anim(t_game *game, int w, int h, char *sprite)
{
	t_list	*anim;
	void	*win_sprite;

	win_sprite = mlx_xpm_file_to_image(game->init, sprite, &w, &h);
	if (!win_sprite)
		if (free_game(game))
			error_exit("anim sprite not correctly loaded");
	anim = ft_lstnew(win_sprite);
	if (!anim)
		if (free_game(game))
			error_exit("t_list anim allocation error");
	ft_lstadd_back(&game->anim, anim);
}

void	sprite_animation(t_game *game)
{
	static t_list	*node;

	if (!game->map->collect)
	{
		if (!node)
			node = game->anim;
		mlx_put_image_to_window(game->init, game->window, node->content,
			game->map->exitx * 64, game->map->exity * 64);
		node = node->next;
	}
}

void	free_anim(t_game *game)
{
	t_list	*next_node;
	t_list	*node;
	t_list	**anim;

	anim = &game->anim;
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
