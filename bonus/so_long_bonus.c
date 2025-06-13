/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:58:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/13 17:12:46 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int c, char **v)
{
	t_map	*game_map;
	char	*format;

	if (c != 2)
		error_exit("more/less then one parameter");
	format = ft_strrchr(v[1], '.');
	if (ft_strncmp(format, ".ber", 4))
		error_exit("invalid map format");
	game_map = input_validation(v[1]);
	begin_game(game_map);
	return (0);
}
