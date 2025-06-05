/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_val_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:37:20 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/05 16:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int file_reading(char *map, char **line)
{
	static int fd;
	
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

int sl_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	return (i);
}

// int	char_count_check(char **mtrx)
// {
// 	int		p_count;
// 	int		e_count;
// 	char	*line;

// 	p_count = 0;
// 	e_count = 0;
// 	while (*mtrx)
// 	{
// 		line = *mtrx;
// 		while (*line)
// 		{
// 			if (*line == 'P')
// 				p_count++;
// 			if (p_count > 1)
// 				return (2);
// 			if (*line == 'E')
// 				e_count++;
// 			if (e_count > 1)
// 				return (3);
// 			line++;
// 		}
// 		mtrx++;
// 	}
// 	return (1);
// }

// void	create_matrix(int fd, int size, char **matrix)
// {
// 	int		idx;
// 	char	*line;

// 	matrix = malloc(size);
// 	if (!matrix)
// 		error_exit("matrix alocation error");
// 	idx = 0;
// 	line = get_next_line(fd);
// 	while (idx < size)
// 	{
// 		line_check(line, size, idx);
// 		matrix[idx++] = line;
// 		line = get_next_line(fd);
// 	}
// 	matrix[idx] = line;
// 	if (char_count_check(matrix) != 1)
// 		return (10);
// 	return (1);
// }

// int	chr_check(char *l)
// {
// 	while (*l)
// 	{
// 		if (*l != '0' || *l != '1' || *l != '\n')
// 		{
// 			if (*l != 'P' || *l != 'C' || *l != 'E')
// 				return (4);
// 		}
// 		l++;
// 	}
// 	return (1);
// }

// int	line_check(char *line, int size, int idx)
// {
// 	static int	s;
// 	int			tmp;

// 	tmp = s;
// 	s = ft_strlen(line);
// 	if (s != tmp || chr_check(line) != 1)
// 		return (8);
// 	if (idx > 0 && idx < size - 1 && *line != '1')
// 		return (5);
// 	while (*line)
// 	{
// 		if ((idx == 0 || idx == size - 1) && *line != '1')
// 			return (6);
// 		line++;
// 	}
// 	line -= 2;
// 	if (idx > 0 && idx < size - 1 && *line != '1')
// 		return (7);
// 	return (1);
// }

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
