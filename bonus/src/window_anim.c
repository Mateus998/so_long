/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:41:04 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/13 17:12:11 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	file_to_image_animation(t_game *game)
{
	game->anim = malloc(sizeof(t_anim));
	if (!game->anim)
		free_game(game, "t_anim allocation error");
	file_to_image_anim_portal_on(game);
	file_to_image_anim_portal_off(game);
	file_to_image_anim_enemy(game);
}

void	file_to_image_anim(t_game *game, t_list **anim, char *sprite)
{
	int		w;
	int		h;
	t_list	*node;
	void	*win_sprite;

	win_sprite = mlx_xpm_file_to_image(game->init, sprite, &w, &h);
	if (!win_sprite)
		free_game(game, "anim sprite not correctly loaded");
	node = ft_lstnew(win_sprite);
	if (!node)
		free_game(game, "t_list allocation error");
	ft_lstadd_back(anim, node);
}

void	file_to_image_anim_enemy(t_game *game)
{
	t_list	*lst;

	lst = NULL;
	file_to_image_anim(game, &lst, "assets/enemy/enemy0.xpm");
	file_to_image_anim(game, &lst, "assets/enemy/enemy1.xpm");
	file_to_image_anim(game, &lst, "assets/enemy/enemy2.xpm");
	file_to_image_anim(game, &lst, "assets/enemy/enemy3.xpm");
	file_to_image_anim(game, &lst, "assets/enemy/enemy4.xpm");
	file_to_image_anim(game, &lst, "assets/enemy/enemy5.xpm");
	game->anim->enemy = lst;
}

void	file_to_image_anim_portal_on(t_game *game)
{
	t_list	*lst;

	lst = NULL;
	file_to_image_anim(game, &lst, "assets/portal_on/portal_on0.xpm");
	file_to_image_anim(game, &lst, "assets/portal_on/portal_on1.xpm");
	file_to_image_anim(game, &lst, "assets/portal_on/portal_on2.xpm");
	file_to_image_anim(game, &lst, "assets/portal_on/portal_on3.xpm");
	file_to_image_anim(game, &lst, "assets/portal_on/portal_on4.xpm");
	game->anim->potal_on = lst;
}

void	file_to_image_anim_portal_off(t_game *game)
{
	t_list	*lst;

	lst = NULL;
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off00.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off01.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off02.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off03.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off04.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off05.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off06.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off07.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off08.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off09.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off10.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off11.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off12.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off13.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off14.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off15.xpm");
	file_to_image_anim(game, &lst, "assets/portal_off/portal_off16.xpm");
	game->anim->portal_off = lst;
}
