/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erros.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:35:02 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/04 16:54:06 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void free_all_exit(char *gnl, char **mtrx, int fd, char *msg)
{
	if (gnl)
		free_get_next_line(fd, gnl);
	if (mtrx)
		free_matrix(mtrx);
	if (fd)
		close (fd);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(1);
}

void	free_get_next_line(int fd, char *line)
{
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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
}
