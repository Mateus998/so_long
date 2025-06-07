#include "../so_long.h"

void render_image(t_game *game)
{
    // look for images
}

void begin_game(t_slong *map)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
        free_map(map, "game allocation fail");
    game->init = mlx_init();
    game->window = mlx_new_window(game->init, 640, 480, "so_long");
    render_image(game);
}