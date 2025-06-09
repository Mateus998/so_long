#include "../so_long.h"

void move_up(t_game *game)
{
    int y;
    int x;

    y = game->map->playery;
    x = game->map->playerx;
    if (game->map->map[y - 1][x] == '1')
        return ;
    game->map->map[y][x] = '0';
    game->map->map[y - 1][x] = 'P';
    game->map->playery -= 1;
    render_image(game);
}

void move_down(t_game *game)
{
    int y;
    int x;

    y = game->map->playery;
    x = game->map->playerx;
    if (game->map->map[y + 1][x] == '1')
        return ;
    game->map->map[y][x] = '0';
    game->map->map[y + 1][x] = 'P';
    game->map->playery += 1;
    render_image(game);
}

void move_left(t_game *game)
{
    int y;
    int x;

    y = game->map->playery;
    x = game->map->playerx;
    if (game->map->map[y][x - 1] == '1')
        return ;
    game->map->map[y][x] = '0';
    game->map->map[y][x - 1] = 'P';
    game->map->playerx -= 1;
    render_image(game);
}

void move_right(t_game *game)
{
    int y;
    int x;

    y = game->map->playery;
    x = game->map->playerx;
    if (game->map->map[y][x + 1] == '1')
        return ;
    game->map->map[y][x] = '0';
    game->map->map[y][x + 1] = 'P';
    game->map->playerx += 1;
    render_image(game);
}
