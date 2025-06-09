#include "../so_long.h"

void game_control(t_game *game)
{
    // funcao para controlar o resultado dos eventos de cada move
}

void begin_game(t_slong *map)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
        free_map(map, "game allocation fail");
    game->init = mlx_init();
    game->map = map;
    game->window = mlx_new_window(game->init, map->width * 64, map->height * 64, "so_long");
    file_to_image(game);
    render_image(game);
    mlx_key_hook(game->window, game_keys, game);
    mlx_hook(game->window, 17, 0, game_close, game);
    mlx_loop(game->init);
}
