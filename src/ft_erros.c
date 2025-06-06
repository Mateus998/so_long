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

int free_game(t_slong *game)
{
	if (game->map)
		free_matrix(game->map);
	free(game);
	return (1);
}
