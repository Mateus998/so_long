/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:15 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/06 18:54:25 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill_check(char **mtx, int y, int x, int collect)
{
	static int	c;
	static int	e;

	if (mtx[y][x] == '1')
		return (0);
	if (mtx[y][x] == 'E')
		e++;
	else if (mtx[y][x] == 'C')
		c++;
	mtx[y][x] = '1';
	flood_fill_check(mtx, y - 1, x, collect);
	flood_fill_check(mtx, y + 1, x, collect);
	flood_fill_check(mtx, y, x - 1, collect);
	flood_fill_check(mtx, y, x + 1, collect);
	if (c == collect && e > 0)
		return (1);
	return (0);
}

void	player_position(t_slong *game)
{
	char	**mtx;
	int		y;
	int		x;

	mtx = game->map;
	y = 0;
	while (mtx[y])
	{
		x = 0;
		while (mtx[y][x])
		{
			if (mtx[y][x] == 'P')
				break ;
			x++;
		}
		if (mtx[y][x] == 'P')
			break ;
		y++;
	}
	game->playerx = x;
	game->playery = y;
}

void	collectibles_count(t_slong *game)
{
	char	**mtx;
	int		y;
	int		x;
	int		count;

	count = 0;
	mtx = game->map;
	y = 0;
	while (mtx[y])
	{
		x = 0;
		while (mtx[y][x])
		{
			if (mtx[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	game->collect = count;
}

void	valid_path_check(t_slong *game, int size)
{
	char	**mtx_cpy;

	mtx_cpy = copy_matrix(game->map, size);
	player_position(game);
	collectibles_count(game);
	if (!flood_fill_check(mtx_cpy, game->playery, game->playerx, game->collect))
		if (free_matrix(mtx_cpy))
			if (free_game(game))
				error_exit("no valid path");
	free_matrix(mtx_cpy);
}

t_slong	*input_validation(char *map)
{
	char	**matrix;
	t_slong	*game;
	int		total_lines;

	map_char_check(map);
	format_check(map);
	total_lines = line_count(map);
	walls_check(map, total_lines);
	matrix = matrix_creation(map);
	game = malloc(sizeof(t_slong));
	if (!game)
		error_exit("game struct allocation error");
	game->map = matrix;
	valid_path_check(game, total_lines);
	return (game);
}
