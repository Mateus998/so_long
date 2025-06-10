/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:58:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/06 18:52:44 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int c, char **v)
{
	t_map	*game_map;

	if (c != 2)
		error_exit("more/less then one parameter");
	game_map = input_validation(v[1]);
	begin_game(game_map);
	printf("PASS\n");
	exit(0);
}
// run on key press