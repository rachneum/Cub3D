#include "../cub3D.h"

void	textures_own_path(t_data *game)
{
	if (!strcmp(game->texture[0], game->texture[1]) ||
		!strcmp(game->texture[0], game->texture[2]) ||
		!strcmp(game->texture[0], game->texture[3]) ||
		!strcmp(game->texture[1], game->texture[2]) ||
		!strcmp(game->texture[1], game->texture[3]) ||
		!strcmp(game->texture[2], game->texture[3]))
		ft_error("ERROR\nEach direction must have its own texture!\n");
}


void	check_texture_exist(t_data *game)
{
	if (!game->texture[0])
		ft_error("ERROR\nMissing NO texture!\n");
	if (!game->texture[1])
		ft_error("ERROR\nMissing SO texture!\n");
	if (!game->texture[2])
		ft_error("ERROR\nMissing WE texture!\n");
	if (!game->texture[3])
		ft_error("ERROR\nMissing EA texture!\n");
	textures_own_path(game);
}

int	check_textures_path(char *path)
{
    int	len;
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_error("ERROR\nOpening texture file failure!\n");
		close (fd);
	}
	len = ft_strlen(path);
	if ((ft_strncmp(path + len - 4, ".xpm", 4)) != 0)
		ft_error("ERROR\nTexture format is invalid!\n");
	return (0);
}

int	check_texture(t_data *game, char *line)
{
	if (check_north(game, line))
		return (1);
	if (check_south(game, line))
		return (1);
	if (check_west(game, line))
		return (1);
	if (check_east(game, line))
		return (1);
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		return (check_color(game, line));
	}
	else if (game->check_floor_color == 0 || game->check_ceiling_color == 0)
		// ft_error("ERROR\nColor is missing!\n");
	return (0);
}
