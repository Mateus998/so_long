/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:38:25 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 17:01:49 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*mapi;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	mapi = ft_strdup(s);
	if (mapi)
	{
		i = 0;
		while (s[i])
		{
			mapi[i] = f(i, s[i]);
			i++;
		}
	}
	return (mapi);
}
