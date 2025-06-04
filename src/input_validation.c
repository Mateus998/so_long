/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:15 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/04 16:55:56 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	input_validation(char *map)
{
	int		fd;
	char	**mtrx;
	int		size;

	mtrx = NULL;
	size = line_count(map);
	if (size < 3)
		error_exit("map to small");
	fd = open(map, O_RDONLY);
	create_matrix(fd, size, mtrx);
	close(fd);
}
