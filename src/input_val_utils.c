/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_val_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:37:20 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/06 11:54:50 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	file_reading(char *map, char **line)
{
	static int	fd;

	if (!fd)
	{
		fd = open(map, O_RDONLY);
		if (fd < 0)
			error_exit("open file error");
	}
	if (*line)
		free(*line);
	*line = get_next_line(fd);
	if (!*line)
	{
		close(fd);
		fd = 0;
		return (0);
	}
	return (1);
}

int	sl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	line_count(char *map)
{
	char	*line;
	int		size;

	size = 0;
	line = NULL;
	while (file_reading(map, &line))
		size++;
	return (size);
}

void	top_bottom_walls(char *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			if (free_get_next_line(map, line))
				error_exit("map not sorounded by walls");
		i++;
	}
}

void	walls_check(char *map, int total_lines)
{
	int		i;
	int		size;
	char	*line;

	i = 1;
	line = NULL;
	file_reading(map, &line);
	size = sl_strlen(line);
	top_bottom_walls(map, line);
	while (file_reading(map, &line) && i < total_lines - 1)
	{
		if (line[0] != '1' || line[size - 1] != '1')
			if (free_get_next_line(map, line))
				error_exit("map not sorounded by walls");
		i++;
	}
	top_bottom_walls(map, line);
	free_get_next_line(map, line);
}
