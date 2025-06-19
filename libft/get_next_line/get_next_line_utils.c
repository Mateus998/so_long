/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:53:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/19 10:53:52 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlchr_gnl(const char *str, int c)
{
	int	i;

	if (!str && c == '\0')
		return (0);
	if (!str)
		return (-1);
	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strdup_gnl(const char *str)
{
	char	*dest;
	int		idx;

	if (!str)
		return (NULL);
	dest = (char *)malloc((ft_strlchr_gnl(str, '\0') + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	idx = -1;
	while (str[++idx])
		dest[idx] = str[idx];
	dest[idx] = '\0';
	return (dest);
}

int	ft_strjoin_gnl(char **temp, const char *read)
{
	size_t		jsize;
	char		*join;
	const char	*copy;
	int			idx;

	if (!read)
		return (-1);
	copy = *temp;
	jsize = ft_strlchr_gnl(copy, '\0') + ft_strlchr_gnl(read, '\0') + 1;
	join = (char *)malloc(jsize * sizeof(char));
	if (join == NULL)
		return (-1);
	idx = 0;
	if (copy)
	{
		while (*copy)
			join[idx++] = *copy++;
		free(*temp);
	}
	while (*read)
		join[idx++] = *read++;
	join[idx] = '\0';
	*temp = join;
	return (1);
}

char	*ft_substr_gnl(char const *str, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	start_cpy;
	size_t			num_memb;

	if (!str)
		return (NULL);
	if ((int)start >= ft_strlchr_gnl(str, '\0') || len == 0)
		return (ft_strdup_gnl(""));
	num_memb = 0;
	start_cpy = start;
	while (str[start_cpy++] && num_memb < len)
		num_memb++;
	sub = (char *)malloc((num_memb + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	num_memb = 0;
	while (str[start] && num_memb < len)
		sub[num_memb++] = str[start++];
	sub[num_memb] = '\0';
	return (sub);
}

int	update_content(char **content, int file_status)
{
	char	*new;
	int		n_idx;
	int		size;

	if (!*content || file_status <= 0)
		return (file_status);
	n_idx = ft_strlchr_gnl(*content, '\n');
	size = ft_strlchr_gnl(*content, '\0');
	new = NULL;
	if (n_idx >= 0 && (*content)[n_idx + 1] != '\0')
	{
		new = ft_substr_gnl(*content, n_idx + 1, size);
		if (!new)
			return (-1);
	}
	free(*content);
	*content = new;
	return (1);
}
