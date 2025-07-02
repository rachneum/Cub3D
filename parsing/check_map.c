#include "../cub3D.h"

/*static int	flood_fill(t_data *game, int y, int x)
{
	if (y < 0 || x < 0 || !game->map_copy[y] || x >= (int)ft_strlen(game->map_copy[y]))
		return (1);
	if (game->map_copy[y][x] == ' ' || game->map_copy[y][x] == '\t' || game->map_copy[y][x] == '\0')
		return (1);
	if (game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'X')
		return (0);
	game->map_copy[y][x] = 'X';//Marquer comme visité.
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

static void	map_is_closed(t_data *game)
{
	int y;
	int	x;

	y = 0;
	game->map_copy = copy_map(game->map);
	if (!game->map_copy)
		ft_error("ERROR: There is nothing in map copy!\n");
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				if (flood_fill(game, y, x))
					ft_free_error("ERROR: Map is not closed around the player!\n", game);
				return ;
			}
			x++;
		}
		y++;
	}
}*/

static void	map_is_closed(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	game->map_copy = copy_map(game->map);
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			/*if (game->map_copy[y][x] == '0')
			{
				ft_free_all_error("Error\nMap must be surrounded by 1!\n", game);
				break;
			}*/

			if (game->map_copy[y][x] == ' '|| game->map_copy[y][x] == '\t')
			{
				if (y == 0)
				{
					if (game->map_copy[y + 1][x] != ' ' && game->map_copy[y + 1][x] != '\t' && game->map_copy[y + 1][x] != '1')
						printf("TEST1\n");
				}
				else if (game->map_copy[y + 1] == NULL)
				{
					if (game->map_copy[y - 1][x] != ' ' && game->map_copy[y - 1][x] != '\t' && game->map_copy[y - 1][x] != '1')
						printf("TEST2\n");
				}
				else if (x == 0)
				{
					if (game->map_copy[y][x + 1] != ' ' && game->map_copy[y][x + 1] != '\t' && game->map_copy[y - 1][x] != '1')
						printf("TEST2\n");
				}
				/*if (y >= 0 && game->map_copy[y - 1][x] >= 0)
					if(game->map_copy[y - 1][x] != ' ' && game->map_copy[y -1][x] != '\t' && game->map_copy[y - 1][x] != '1')
						ft_free_all_error("Error1!\n", game);
				if (y != '\0' && game->map_copy[y + 1][x] <= y)
					if(game->map_copy[y + 1][x] != ' ' && game->map_copy[y +1][x] != '\t' && game->map_copy[y + 1][x] != '1')
						ft_free_all_error("Error2!\n", game);
				if (x >= 0 && game->map_copy[y][x - 1] >= x)
					if(game->map_copy[y][x - 1] != ' ' && game->map_copy[y][x - 1] != '\t' && game->map_copy[y][x - 1] != '1')
						ft_free_all_error("Error3!\n", game);
				if (x < '\0' && game->map_copy[y][x + 1] <= x)
					if(game->map_copy[y][x + 1] != ' ' && game->map_copy[y][x + 1] != '\t' && game->map_copy[y][x + 1] != '1')
						ft_free_all_error("Error4!\n", game);*/
			}
			x++;
		}
		y++;
	}
}

static int	start_pos(t_data *game)
{
	int y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S' || game->map[y][x] == 'E' || game->map[y][x] == 'W')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	else if (!count)
		return (0);
	return (1);
}

void	map_is_valid(t_data *game)
{
	int i;

	i = 0;
	if (!start_pos(game))
		ft_free_error("ERROR: Wrong player's starting position!\n", game);
	map_is_closed(game);
	printf("MAP COPY:\n");
	while (game->map_copy[i])
		printf("%s\n", game->map_copy[i++]);
}
