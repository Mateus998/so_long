/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:58:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/17 12:20:04 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int c, char **v)
{
	t_map	*game_map;
	char	*name;

	if (c != 2)
		error_exit("more/less then one parameter");
	name = ft_strrchr(v[1], '.');
	if (ft_strncmp(name, ".ber", 4))
		error_exit("invalid map name");
	game_map = input_validation(v[1]);
	begin_game(game_map);
	return (0);
}
