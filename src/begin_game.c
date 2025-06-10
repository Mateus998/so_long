#include "../so_long.h"

int game_close(t_game *game)
{
	free_game(game);
    exit(0);
	return (0);
}

void begin_game(t_map *map)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
        if (free_map(map))
            error_exit("game allocation fail");
    game->init = mlx_init();
    game->map = map;
    game->window = mlx_new_window(game->init, map->width * 64, map->height * 64, "so_long");
    file_to_image(game);
    render_image(game);
    game->key_a = 0;
    game->key_s = 0;
    game->key_d = 0;
    game->key_w = 0;
    mlx_hook(game->window, 17, 0, game_close, game);
    mlx_hook(game->window, 2, 1L<<0, key_press, game);
    mlx_hook(game->window, 3, 1L<<1, key_release, game);
    mlx_loop_hook(game->init, key_loop, game);
    mlx_loop(game->init);
}
