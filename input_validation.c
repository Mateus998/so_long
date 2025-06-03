/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:15 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/03 19:00:54 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_exit(char *msg)
{
    perror(msg);
    exit(1);
}

char *join_read(char *line_map, char *read_buff)
{
        
}


void free_get_next_line(int fd, char *line)
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

int create_matrix(int fd, int size, char **matrix)
{
    int idx;
    char *line;

    matrix = malloc(size);
    if (!matrix)
        error_exit("matrix alocation error");
    idx = 0;
    line = get_next_line(fd);
    if (!line_check(line, size, idx));
        return (free_get_next_line(fd, line), 0);
    while (line && idx < size)
    {
        //line check e matrix fill
    }
    return (1);
}

int line_check(char *mtrx, int size, int idx)
{
    static int s;
    int tmp;
    
    tmp = s;
    s = ft_strlen(mtrx);
    if (s != tmp)
        return (0);
    if (idx > 0 && idx < size - 1 && *mtrx != '1')
        return (0);
    while (*mtrx)
    {
        if ((idx == 0 || idx == size - 1) && *mtrx != '1')
            return (0);
        mtrx++;
    }
    if (idx > 0 && idx < size - 1 && *mtrx != '1')
        return (0);
    return (1);
}

int line_count(int fd, char *map)
{
    int fd;
    char *line;
    int size;
    
    fd = open(map, O_RDONLY);
    if (fd == -1)
        error_exit("error on file opening");
    line = get_next_line(fd);
    size = 0;
    while (line)
    {
        free(line);
        size++;
        line = get_next_line(fd);
    }
    close (fd);
    return (size);
}

void	free_array(char **array, char *msg)
{
	while (*array)
		free(*array);
	free(array);
    error_exit(msg);
}

void input_validation(char *map)
{
    int fd;
    char **mtrx;
    int i;
    int size;
    
    size = line_count(fd, map);
    if (size < 3)
        error_exit("map to small");
    fd = open(map, O_RDONLY);
    if (!create_matrix(fd, size, mtrx))
    {
        free_array(mtrx, "map invalid");
    }
    close(fd);
}
