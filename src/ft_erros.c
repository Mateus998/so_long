/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:35:02 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/06 18:18:16 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_exit(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void free_map(t_slong *map, char *msg)
{
	free_matrix(map->map);
	free(map);
	error_exit(msg);
}

void free_game(t_game *game, char *msg, int error)
{
	if (game->map)
		free_matrix(game->map->map);
	free(game->map);
	if (game->win)
		free(game->win);
	free(game);
	if (error)
		error_exit(msg);
	exit(0);
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
	int i;

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
