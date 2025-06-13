/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:13:41 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/13 16:15:39 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

typedef struct s_map
{
	char			**map;
	int				collect;
	int				playerx;
	int				playery;
	int				exitx;
	int				exity;
	int				width;
	int				height;
}					t_map;

typedef struct s_win
{
	void			*floor;
	void			*wall;
	void			*collect;
	void			*portal_p;
	void			*player_w;
	void			*player_a;
	void			*player_s;
	void			*player_d;
}					t_win;

typedef struct s_anim
{
	struct s_list	*potal_on;
	struct s_list	*portal_off;
	struct s_list	*enemy;
}					t_anim;

typedef struct s_game
{
	struct s_anim	*anim;
	struct s_map	*map;
	struct s_win	*win;
	void			*init;
	void			*window;
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				event;
}					t_game;

// game
void				begin_game(t_map *game);

// window
void				render_image(t_game *game);
void				file_to_image(t_game *game);
void				exit_window(t_game *game);
void				put_image_player(t_game *game, int y, int x);
void				put_image(t_game *game, int y, int x);
void				file_to_image(t_game *game);
void				file_to_image_player(t_game *game, int w, int h);

// animations
void				file_to_image_anim(t_game *game, t_list **anim,
						char *sprite);
void				file_to_image_animation(t_game *game);
void				file_to_image_anim_enemy(t_game *game);
void				file_to_image_anim_portal_on(t_game *game);
void				file_to_image_anim_portal_off(t_game *game);
void				sprite_animation(t_game *game);
void				enemy_animation(t_game *game);

// controls
int					game_loop(void *param);
int					key_release(int key, t_game *game);
int					key_press(int key, t_game *game);
void				move_control(t_game *game, int y, int x, char m);
void				move(t_game *game, int y, int x, char m);
int					move_event(char **map, int y, int x);

// exits
void				free_anim(t_game *game, t_list **anim);
void				error_exit(char *msg);
int					free_get_next_line(char *map, char *line);
int					free_matrix(char **mtrx);
void				free_game(t_game *game, char *msg);
int					free_map(t_map *map);
int					game_close(t_game *game);

// input
int					validate_char(char c);
t_map				*input_validation(char *map);
int					file_reading(char *map, char **line);
void				format_check(char *map);
int					sl_strlen(char *str);
int					line_count(char *map);
char				**matrix_creation(char *map);
void				top_bottom_walls(char *map, char *line);
void				walls_check(char *map, int total_lines);
char				*player_exit_count(char c);
void				map_char_check(char *map);
char				**copy_matrix(char **mtx, int size);
int					flood_fill_check(char **mtx, int y, int x, int collect);
void				player_position(t_map *game);
void				collectibles_count(t_map *game);
void				valid_path_check(t_map *game, int size);

#endif