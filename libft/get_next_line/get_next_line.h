/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:54:29 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 16:09:51 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;
}					t_gnl;

char				*get_next_line(int fd);
int					ft_strlchr_gnl(const char *str, int c);
char				*ft_strdup_gnl(const char *str);
int					ft_strjoin_gnl(char **temp, const char *read);
char				*ft_substr_gnl(char const *str, unsigned int start,
						size_t len);
int					update_content(char **content, int file_status);

#endif