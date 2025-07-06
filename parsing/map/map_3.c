#include "../../cub3d.h"

static void	check_surroundings(t_data *game, int y, int x)
{
	if (y > 0 && x < (int)ft_strlen(game->map_copy[y - 1]) && 
		(game->map_copy[y - 1][x] == ' ' || game->map_copy[y - 1][x] == '\t'))
		free_err_all_maps("Error\nInvalid map!\n", game);
	if (game->map_copy[y + 1] && x < (int)ft_strlen(game->map_copy[y + 1]) && 
		(game->map_copy[y + 1][x] == ' ' || game->map_copy[y + 1][x] == '\t'))
		free_err_all_maps("Error\nInvalid map!\n", game);
	if (x > 0 && (game->map_copy[y][x - 1] == ' ' || game->map_copy[y][x - 1] == '\t'))
		free_err_all_maps("Error\nInvalid map!\n", game);
	if (x + 1 < (int)ft_strlen(game->map_copy[y]) && 
		(game->map_copy[y][x + 1] == ' ' || game->map_copy[y][x + 1] == '\t'))
		free_err_all_maps("Error\nInvalid map!\n", game);
}

void	check_invalid_zero(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			if (game->map_copy[y][x] == '0')
				check_surroundings(game, y, x);
			x++;
		}
		y++;
	}
}

void	map_borders(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			if (y == 0 || game->map_copy[y + 1] == NULL)
			{
				if (game->map_copy[y][x] == '0')
				free_err_all_maps("Error\nInvalid map!\n", game);
			}
			if (x == 0 || x == (int)(ft_strlen(game->map_copy[y]) - 1))
			{
				if (game->map_copy[y][x] == '0')
				free_err_all_maps("Error\nInvalid map!\n", game);
			}
			x++;
		}
		y++;
	}
}

int	flood_fill(t_data *game, int y, int x)
{
	if (y < 0 || x < 0 || !game->map_copy[y] || x >= (int)ft_strlen(game->map_copy[y]))
		return (1);
	if (game->map_copy[y][x] == ' ' || game->map_copy[y][x] == '\t')
		return (1);
	if (game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'X')
		return (0);
	game->map_copy[y][x] = 'X';
	if (flood_fill(game, y - 1, x))
		return (1);
	if (flood_fill(game, y + 1, x))
		return (1);
	if (flood_fill(game, y, x - 1))
		return (1);
	if (flood_fill(game, y, x + 1))
		return (1);
	return (0);
}
