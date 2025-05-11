#include "../cub3D.h"

static int  map_is_rectangular(t_data *game)
{
    int	y;

	y = 0;
	while (game->map[y])
	{
		if (ft_strlen(game->map[y]) != ft_strlen(game->map[0]))
			return (0);
		y++;
	}
	return (1);
}

static int	map_is_closed(t_data *game)
{
	int	    x;
	int	    y;
	int 	width;

	if (!game->map || !game->map[0])
		return (0);
	width = ft_strlen(game->map[0]);
	x = 0;
	while (x < width)
	{
		if (game->map[0][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (game->map[y + 1])
	{
		if (game->map[y][0] != '1' || game->map[y][width - 1] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (x < width)
	{
		if (game->map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

void    map_is_valid(t_data *game)
{
    if (!map_is_rectangular(game))
        ft_error("ERROR: Map is not rectangular!\n");//ft_free_error et pas ft_error.
    else if (!map_is_closed(game))
        ft_error("ERROR: Map is not closed!\n");
}
