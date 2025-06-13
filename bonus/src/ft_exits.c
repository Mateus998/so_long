/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:35:02 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/13 16:17:11 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_exit(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

int	free_map(t_map *map)
{
	free_matrix(map->map);
	free(map);
	return (1);
}

void	free_game(t_game *game, char *msg)
{
	if (!game)
		return ;
	if (game->anim)
	{
		free_anim(game, &game->anim->enemy);
		free_anim(game, &game->anim->portal_off);
		free_anim(game, &game->anim->potal_on);
		free(game->anim);
	}
	if (game->map)
		free_map(game->map);
	if (game->win)
		exit_window(game);
	if (game->init)
	{
		mlx_destroy_display(game->init);
		free(game->init);
	}
	free(game);
	if (msg)
		error_exit(msg);
}

int	free_get_next_line(char *map, char *line)
{
	file_reading(map, &line);
	while (line)
		file_reading(map, &line);
	return (1);
}

int	free_matrix(char **mtrx)
{
	int	i;

	i = 0;
	if (mtrx)
	{
		while (mtrx[i])
		{
			free(mtrx[i]);
			i++;
		}
		free(mtrx);
		mtrx = NULL;
	}
	return (1);
}
