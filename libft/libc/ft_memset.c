/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:13:11 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 17:25:38 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cs;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	cs = (unsigned char *)s;
	while (n--)
		cs[i++] = (unsigned char)c;
	return (s);
}
