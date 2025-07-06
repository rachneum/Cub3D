#include "../cub3d.h"

void    ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}

void free_entire_fd(t_data *game)
{
    int i;

    i = 0;
    if (!game->entire_fd)
        return ;
    while (game->entire_fd[i])
        free(game->entire_fd[i++]);
    free(game->entire_fd);
    game->entire_fd = NULL;
}

void    free_error_fd(char *str, t_data *game)
{
    free_entire_fd(game);
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}

void    free_map(t_data *game)
{
    int i;

    i = 0;
    if (!game->map)
        return ;
    while (game->map[i])
        free(game->map[i++]);
    free(game->map);
    game->map = NULL;
}

void    free_error_map(char *str, t_data *game)
{
    free_map(game);
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}

void    free_map_copy(t_data *game)
{
    int i;

    i = 0;
    if (!game->map_copy)
        return ;
    while (game->map_copy[i])
        free(game->map_copy[i++]);
    free(game->map_copy);
    game->map_copy = NULL;
}

void    free_err_all_maps(char *str, t_data *game)
{
    free_map(game);
    free_map_copy(game);
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}
