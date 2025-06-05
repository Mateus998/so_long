/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:41 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/05 22:53:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
// errors
void	error_exit(char *msg);
// void free_all_exit(char *gnl, char **mtrx, int fd, char *msg);
int	free_get_next_line(char *map, char *line);
void	free_matrix(char **mtrx);

// input
void	input_validation(char *map);
int file_reading(char *map, char **line);
void format_check(char *map);
int sl_strlen(char *str);
// int		char_count_check(char **mtrx);
// void		create_matrix(int fd, int size, char **matrix);
// int		chr_check(char *l);
// int		line_check(char *line, int size, int idx);
int		line_count(char *map);

#endif