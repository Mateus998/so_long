/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:15 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/05 17:22:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void format_check(char *map)
{
	int size;
	int temp;
	char *line;

	line = NULL;
	file_reading(map, &line);
	size = sl_strlen(line);
	while(file_reading(map, &line))
	{
		temp = sl_strlen(line);
		if (temp != size)
			if (free_get_next_line(map, line))
				error_exit("map is not rectangular");
	}
}

void top_bottom_walls(char *map, char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			if (free_get_next_line(map, line))
				error_exit("map not sorounded by walls");
		i++;
	}
}

void walls_check(char *map, int total_lines)
{
	int i;
	int size;
	char *line;

	i = 1;
	line = NULL;
	file_reading(map, &line);
	size = sl_strlen(line);
	top_bottom_walls(map, line);
	while(file_reading(map, &line) && i < total_lines - 1)
	{
		if (line[0] != '1' || line[size - 1] != '1')
			if (free_get_next_line(map, line))
				error_exit("map not sorounded by walls");
		i++;
	}
	top_bottom_walls(map, line);
	free_get_next_line(map, line);
}

char *player_exit_count(char c)
{
	static int p_count;
	static int e_count;

	if (c == 'P')
	{
		p_count++;
		if (p_count > 1)
			return ("to many players");
	}
	else if (c == 'E')
	{
		e_count++;
		if (e_count > 1)
			return ("to many exits");
	}
	return (NULL);
}

void map_char_check(char *map)
{
	char *line;
	char *res;
	int i;

	line = NULL;
	i = 0;
	while(file_reading(map, &line))
	{
		while(line[i])
		{
			if (line[i] != '0' && line[i] != '1' && line[i] != '\n')
			{
				if (line[i] != 'P' && line[i] != 'C' && line[i] != 'E')
					if (free_get_next_line(map, line))
						error_exit("invalid char detected");
			}
			res = player_exit_count(line[i]);
			if (res)
				if (free_get_next_line(map, line))
						error_exit(res);
			i++;
		}
	}
}

void	input_validation(char *map)
{
	int total_lines;

	
	map_char_check(map);
	format_check(map);
	total_lines = line_count(map);
	walls_check(map, total_lines);
	// matrix_creation(map);
}
