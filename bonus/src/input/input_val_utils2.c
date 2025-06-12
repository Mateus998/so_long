/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_val_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:53:29 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/12 18:34:06 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	format_check(char *map)
{
	int		size;
	int		temp;
	char	*line;

	line = NULL;
	file_reading(map, &line);
	size = sl_strlen(line);
	while (file_reading(map, &line))
	{
		temp = sl_strlen(line);
		if (temp != size)
			if (free_get_next_line(map, line))
				error_exit("map is not rectangular");
	}
}

char	*player_exit_count(char c)
{
	static int	p_count;
	static int	e_count;
	static int	c_count;

	if (c == 'P')
		p_count++;
	else if (c == 'E')
		e_count++;
	else if (c == 'C')
		c_count++;
	if (p_count > 1 || e_count > 1)
		return ("to many players and/or exits");
	if (p_count == 0 || e_count == 0 || c_count == 0)
		return ("no player, exit and/or collectibles");
	return (NULL);
}

void	map_char_check(char *map)
{
	char	*line;
	int		i;
	char	*res;

	line = NULL;
	if (!file_reading(map, &line))
		error_exit("empty map");
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (!validate_char(line[i]))
				if (free_get_next_line(map, line))
					error_exit("invalid char detected");
			res = player_exit_count(line[i]);
			i++;
		}
		file_reading(map, &line);
	}
	if (res)
		error_exit(res);
}

char	**matrix_creation(char *map)
{
	char	**mtx;
	int		i;
	char	*line;
	int		size;

	mtx = NULL;
	size = line_count(map);
	mtx = (char **)malloc((size + 1) * sizeof(char *));
	if (!mtx)
		error_exit("matrix allocation fail");
	i = 0;
	line = NULL;
	while (file_reading(map, &line))
	{
		size = sl_strlen(line);
		mtx[i] = (char *)malloc((size + 1) * sizeof(char));
		if (!mtx[i])
			if (free_matrix(mtx))
				if (free_get_next_line(map, line))
					error_exit("matrix line allocation fail");
		ft_strlcpy(mtx[i], line, size + 1);
		i++;
	}
	mtx[i] = NULL;
	return (mtx);
}

char	**copy_matrix(char **mtx, int size)
{
	char	**mtx_cpy;
	int		i;

	mtx_cpy = NULL;
	mtx_cpy = (char **)malloc((size + 1) * sizeof(char *));
	if (!mtx_cpy)
		if (free_matrix(mtx))
			error_exit("matrix dup allocation error");
	i = 0;
	while (mtx[i])
	{
		mtx_cpy[i] = ft_strdup(mtx[i]);
		if (!mtx_cpy[i])
			if (free_matrix(mtx_cpy))
				if (free_matrix(mtx))
					error_exit("matrix dup line allocation error");
		i++;
	}
	mtx_cpy[i] = NULL;
	return (mtx_cpy);
}
