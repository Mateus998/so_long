/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:55:46 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 16:41:10 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	if (!s)
		return ;
	cs = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		cs[i] = 0;
		i++;
	}
}
