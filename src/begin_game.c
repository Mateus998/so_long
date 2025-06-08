#include "../so_long.h"

void render_image(t_game *game)
{
    int y;
    int x;
    t_slong *map;
    
    if (!game || !game->map || !game->map->map)
    {
        ft_printf("Erro: game/map/map->map não inicializado\n");
        return;
    }
    if (!game->img_wall || !game->img_floor)
    {
        ft_printf("Erro: imagens não carregadas corretamente\n");
        return;
    }
    map = game->map;
    y = 0;
    while (map->map[y])
    {
        x = 0;
        while (map->map[y][x])
        {
            if (map->map[y][x] == '1')
                mlx_put_image_to_window(game->init, game->window, game->img_wall, x * 64, y * 64);
            else
                mlx_put_image_to_window(game->init, game->window, game->img_floor, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

int game_keys(int key, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (key == 53)
    {
        mlx_destroy_window(game->init, game->window);
        free_game(game, "EXIT", 0);
        exit(0);
    }
    return (0);
}

int game_close(t_game *game)
{
	mlx_destroy_window(game->init, game->window);
    free_game(game, "EXIT", 0);
	exit(0);
	return (0);
}

void begin_game(t_slong *map)
{
    t_game *game;
    int height;
    int width;
    int w;
    int h;

    game = malloc(sizeof(t_game));
    if (!game)
        free_map(map, "game allocation fail");
    game->init = mlx_init();
    height = map->height * 64;
    width = map->width * 64;
    game->map = map;
    game->window = mlx_new_window(game->init, width, height, "so_long");
    
    game->img_floor = mlx_xpm_file_to_image(game->init, "assets/grass.xpm", &w, &h);
    game->img_wall = mlx_xpm_file_to_image(game->init, "assets/stone.xpm", &w, &h);
    
    render_image(game);
    mlx_key_hook(game->window, game_keys, game);
    mlx_hook(game->window, 17, 0, game_close, game);
    mlx_loop(game->init);
}
