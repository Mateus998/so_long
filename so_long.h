/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:41 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/06 18:55:52 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"

typedef struct s_slong
{
	char	**map;
	int		collect;
	int		playerx;
	int		playery;
	int width;
	int height;
}			t_slong;

typedef struct s_win
{
	void *floor;
	void *wall;
	void *collect;
	void *portal_on;
	void *portal_off;
	void *portal_p;
	void *player;
} t_win;

typedef struct s_game
{
	struct s_slong	*map;
	struct s_win *win;
	void *init;
	void *window;
}			t_game;

// game
void begin_game(t_slong *game);

// window
void render_image(t_game *game);
void file_to_image(t_game *game);

// moves
void move_up(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);

// controls
int game_close(t_game *game);
int game_keys(int key, void *param);

// errors
void		error_exit(char *msg);
int			free_get_next_line(char *map, char *line);
int			free_matrix(char **mtrx);
void free_game(t_game *game, char *msg, int error);
void free_map(t_slong *map, char *msg);

// input
t_slong		*input_validation(char *map);
int			file_reading(char *map, char **line);
void		format_check(char *map);
int			sl_strlen(char *str);
int			line_count(char *map);
char		**matrix_creation(char *map);
void		top_bottom_walls(char *map, char *line);
void		walls_check(char *map, int total_lines);
char		*player_exit_count(char c);
void		map_char_check(char *map);
char		**copy_matrix(char **mtx, int size);
int			flood_fill_check(char **mtx, int y, int x, int collect);
void		player_position(t_slong *game);
void		collectibles_count(t_slong *game);
void		valid_path_check(t_slong *game, int size);

#endif