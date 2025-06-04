/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:41 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/04 16:56:56 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
// errors
void	error_exit(char *msg);
void free_all_exit(char *gnl, char **mtrx, int fd, char *msg);
void	free_get_next_line(int fd, char *line);
void	free_matrix(char **mtrx);

// input
void	input_validation(char *map);
int		char_count_check(char **mtrx);
void		create_matrix(int fd, int size, char **matrix);
int		chr_check(char *l);
int		line_check(char *line, int size, int idx);
int		line_count(char *map);

#endif