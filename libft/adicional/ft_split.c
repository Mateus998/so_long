/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:11:55 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:06:08 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	**free_split(char **split, size_t j)
{
	while (j > 0)
	{
		j--;
		free(split[j]);
	}
	free(split);
	return (NULL);
}

static char	*word(char const *s, char c, size_t i)
{
	size_t	word;
	char	*pword;
	size_t	start;

	word = 0;
	start = i;
	while (s[i] && s[i] != c)
	{
		word++;
		i++;
	}
	pword = (char *)malloc((word + 1) * sizeof(char));
	if (pword == NULL)
		return (NULL);
	ft_strlcpy(pword, &s[start], word + 1);
	return (pword);
}

static char	**split_fill(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			split[j] = word(s, c, i);
			if (split[j] == NULL)
				return (free_split(split, j));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (s != NULL)
	{
		split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
		if (split == NULL)
			return (NULL);
		split = split_fill(split, s, c);
	}
	else
	{
		return (NULL);
	}
	return (split);
}
