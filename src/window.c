#include "../so_long.h"

void exit_window(t_game *game)
{
    if (game->win->collect)
        mlx_destroy_image(game->init, game->win->collect);
    if (game->win->floor)
        mlx_destroy_image(game->init, game->win->floor);
    if (game->win->player)
        mlx_destroy_image(game->init, game->win->player);
    if (game->win->portal_off)
        mlx_destroy_image(game->init, game->win->portal_off);
    if (game->win->portal_on)
        mlx_destroy_image(game->init, game->win->portal_on);
    if (game->win->portal_p)
        mlx_destroy_image(game->init, game->win->portal_p);
    if (game->win->wall)
        mlx_destroy_image(game->init, game->win->wall);
    mlx_destroy_window(game->init, game->window);
    free(game->win);
}

void put_image(t_game *game, int y, int x)
{
    if (game->map->map[y][x] == '1')
        mlx_put_image_to_window(game->init, game->window, game->win->wall, x * 64, y * 64);
    else if (game->map->map[y][x] == '0')
        mlx_put_image_to_window(game->init, game->window, game->win->floor, x * 64, y * 64);
    else if (game->map->map[y][x] == 'C')
        mlx_put_image_to_window(game->init, game->window, game->win->collect, x * 64, y * 64);
    else if (game->map->map[y][x] == 'E')
        mlx_put_image_to_window(game->init, game->window, game->win->portal_off, x * 64, y * 64);
    else if (game->map->map[y][x] == 'F')
        mlx_put_image_to_window(game->init, game->window, game->win->portal_on, x * 64, y * 64);
    else if (game->map->map[y][x] == 'G')
        mlx_put_image_to_window(game->init, game->window, game->win->portal_p, x * 64, y * 64);
    else if (game->map->map[y][x] == 'P')
        mlx_put_image_to_window(game->init, game->window, game->win->player, x * 64, y * 64);
}

void render_image(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (game->map->map[y])
    {
        x = 0;
        while (game->map->map[y][x])
        { 
            put_image(game, y, x);
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
        if (free_game(game))
            error_exit("t_win allocaion error");
    win->floor = mlx_xpm_file_to_image(game->init, "assets/grass.xpm", &w, &h);
    win->wall = mlx_xpm_file_to_image(game->init, "assets/stone.xpm", &w, &h);
    win->collect = mlx_xpm_file_to_image(game->init, "assets/collect.xpm", &w, &h);
    win->player = mlx_xpm_file_to_image(game->init, "assets/player_idle.xpm", &w, &h);
    win->portal_off = mlx_xpm_file_to_image(game->init, "assets/portal_off.xpm", &w, &h);
    win->portal_on = mlx_xpm_file_to_image(game->init, "assets/portal_on.xpm", &w, &h);
    win->portal_p = mlx_xpm_file_to_image(game->init, "assets/portal_player.xpm", &w, &h);
    if (!win->collect || !win->floor || !win->player || !win->portal_off || !win->portal_on || !win->portal_p || !win->wall)
        if (free_game(game))
            error_exit("images not correctly loaded");
    game->win = win;
}
