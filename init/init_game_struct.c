#include "../cub3D.h"

void    init_game_struct(t_data *game)
{
    game->map = NULL;
    game->texture[0] = NULL;
    game->texture[1] = NULL;
    game->texture[2] = NULL;
    game->texture[3] = NULL;
    game->floor_color = -1;
    game->ceiling_color = -1;//??
}
