/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_val_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:37:20 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/05 22:16:56 by marvin           ###   ########.fr       */
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
