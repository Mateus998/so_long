#include "../so_long.h"

void exit_game(t_game *game)
{
    mlx_destroy_window(game->init, game->window);
    free_game(game, "EXIT", 0);
}

int game_keys(int key, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (key == 53)
        exit_game(game);
    else if (key == 13)
        move_up(game);
    else if (key == 0)
        move_left(game);
    else if (key == 1)
        move_down(game);
    else if (key == 2)
        move_right(game);
    return (0);
}

int game_close(t_game *game)
{
	exit_game(game);
	return (0);
}