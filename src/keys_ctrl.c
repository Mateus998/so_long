#include "../so_long.h"

void move_control(t_game *game, int event, int y, int x, char m)
{
    if (game->map->map[game->map->playery][game->map->playerx] == 'G')
        game->map->map[game->map->playery][game->map->playerx] = 'E';
    else
        game->map->map[game->map->playery][game->map->playerx] = '0';
    if (m == 'w')
        game->map->map[y][x] = 'W';
    else if (m == 'a')
        game->map->map[y][x] = 'A';
    else if (m == 's')
        game->map->map[y][x] = 'P';
    else if (m == 'd')
        game->map->map[y][x] = 'D';
    if (event == 1)
    {
        game->map->collect--;
        if (!game->map->collect)
            game->map->map[game->map->exity][game->map->exitx] = 'F';
    }
    else if (event == 2)
        game->map->map[y][x] = 'G';
    else if (event == 3)
        game_close(game);
}

void move(t_game *game, int y, int x, char m)
{
    int event;
    static int moves;

    event = 0;
    if (game->map->map[y][x] == '1')
        return ;
    else if (game->map->map[y][x] == 'C')
        event = 1;
    else if (game->map->map[y][x] == 'E')
        event = 2;
    else if (game->map->map[y][x] == 'F')
        event = 3;
    move_control(game, event, y, x, m);
    moves++;
    ft_printf("%i\n", moves);
    game->map->playery = y;
    game->map->playerx = x;
    render_image(game);
}

int game_keys(int key, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (key == 65307)
        game_close(game);
    else if (key == 119)
        move(game, game->map->playery - 1, game->map->playerx, 'w');
    else if (key == 97)
        move(game, game->map->playery, game->map->playerx - 1, 'a');
    else if (key == 115)
        move(game, game->map->playery + 1, game->map->playerx, 's');
    else if (key == 100)
        move(game, game->map->playery, game->map->playerx + 1, 'd');
    return (0);
}

int game_close(t_game *game)
{
	free_game(game);
    exit(0);
	return (0);
}