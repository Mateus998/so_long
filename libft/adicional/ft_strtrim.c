/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:54:33 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:01:45 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	end_str(char const *s1, char const *set)
{
	long int	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strchr(set, (int)s1[i]))
			i--;
		else
			break ;
	}
	return (i);
}

static int	start_str(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, (int)s1[i]))
			i++;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	trimlen;

	if (s1 != NULL && set != NULL)
	{
		end = end_str(s1, set);
		start = start_str(s1, set);
		if (start > end)
			trimlen = 0;
		else
			trimlen = end - start + 1;
		trim = (char *)malloc((trimlen + 1) * sizeof(char));
		if (trim == NULL)
			return (NULL);
		ft_strlcpy(trim, &s1[start], trimlen + 1);
	}
	else
		return (ft_strdup(""));
	return (trim);
}
