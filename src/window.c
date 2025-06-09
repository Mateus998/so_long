#include "../so_long.h"

void render_image(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (game->map->map[y])
    {
        x = 0;
        while (game->map->map[y][x])
        { //adaptar para o mlx_destroi_image posteriormente
            if (game->map->map[y][x] == '1')
                mlx_put_image_to_window(game->init, game->window, game->win->wall, x * 64, y * 64);
            else if (game->map->map[y][x] == '0')
                mlx_put_image_to_window(game->init, game->window, game->win->floor, x * 64, y * 64);
            else if (game->map->map[y][x] == 'C')
                mlx_put_image_to_window(game->init, game->window, game->win->collect, x * 64, y * 64);
            else if (game->map->map[y][x] == 'E')
                mlx_put_image_to_window(game->init, game->window, game->win->portal_off, x * 64, y * 64);
            else if (game->map->map[y][x] == 'P')
                mlx_put_image_to_window(game->init, game->window, game->win->player, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

void file_to_image(t_game *game)
{
    t_win *win;
    int w;
    int h;

    win = malloc (sizeof(t_win));
    if (!win)
        free_game(game, "t_win allocaion error", 1);
    win->floor = mlx_xpm_file_to_image(game->init, "assets/grass.xpm", &w, &h);
    win->wall = mlx_xpm_file_to_image(game->init, "assets/stone.xpm", &w, &h);
    win->collect = mlx_xpm_file_to_image(game->init, "assets/collect.xpm", &w, &h);
    win->player = mlx_xpm_file_to_image(game->init, "assets/player_idle.xpm", &w, &h);
    win->portal_off = mlx_xpm_file_to_image(game->init, "assets/portal_off.xpm", &w, &h);
    win->portal_on = mlx_xpm_file_to_image(game->init, "assets/portal_on.xpm", &w, &h);
    win->portal_p = mlx_xpm_file_to_image(game->init, "assets/portal_player.xpm", &w, &h);
    if (!win->collect || !win->floor || !win->player || !win->portal_off || !win->portal_on || !win->portal_p || !win->wall)
        free_game(game, "images not correctly loaded", 1);
    game->win = win;
}