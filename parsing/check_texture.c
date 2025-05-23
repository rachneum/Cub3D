#include "../cub3D.h"

void	check_texture_exist(t_data *game)
{
	if (!game->texture[0])
		ft_error("ERROR: Missing NO texture!\n");
	if (!game->texture[1])
		ft_error("ERROR: Missing SO texture!\n");
	if (!game->texture[2])
		ft_error("ERROR: Missing WE texture!\n");
	if (!game->texture[3])
		ft_error("ERROR: Missing EA texture!\n");
}

int	check_textures_path(char *path)//Vérifie chemin vers la texture et format.
{
    int	len;
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_error("ERROR: Opening texture file failure!\n");
		close (fd);
	}
	len = ft_strlen(path);
	if ((ft_strncmp(path + len - 4, ".xpm", 4)) != 0)
		ft_error("ERROR: Texture format is invalid!\n");//Vérifie format fichier texture.
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
		printf ("%s\n", line);
	}
	return (0);
}
