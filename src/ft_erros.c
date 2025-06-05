/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:35:02 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/05 22:54:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_exit(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

// void free_all_exit(char *gnl, char **mtrx, int fd, char *msg)
// {
// 	if (gnl)
// 		free_get_next_line(fd, gnl);
// 	if (mtrx)
// 		free_matrix(mtrx);
// 	if (fd)
// 		close (fd);
// 	if (msg)
// 		ft_putendl_fd(msg, 2);
// 	exit(1);
// }

int	free_get_next_line(char *map, char *line)
{
	file_reading(map, &line);
	while (line)
		file_reading(map, &line);
	return (1);
}

void	free_matrix(char **mtrx)
{
	if (mtrx)
	{
		while (*mtrx)
		{
			free(*mtrx);
			mtrx++;
		}
		free(mtrx);
	}
	*mtrx = NULL;
}
