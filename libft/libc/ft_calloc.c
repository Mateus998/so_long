/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:31:39 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 16:41:22 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		ptr = malloc(0);
	else if (nmemb <= ((size_t)-1) / size)
		ptr = malloc(nmemb * size);
	else
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
