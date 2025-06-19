/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:58:20 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 17:07:45 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	tstart;
	size_t			nmemb;

	nmemb = 0;
	tstart = start;
	if (s != NULL && start < ft_strlen(s) && len != 0)
	{
		while (s[tstart++] && nmemb < len)
			nmemb++;
		sub = (char *)malloc((nmemb + 1) * sizeof(char));
		if (sub == NULL)
			return (NULL);
		ft_strlcpy(sub, &s[start], nmemb + 1);
	}
	else
	{
		return (ft_strdup(""));
	}
	return (sub);
}
