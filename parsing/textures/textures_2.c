#include "../../cub3d.h"

void	check_textures_path(char *path)
{
	int	len;
	int	fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_error("Error\nInvalid file!\n");
		close (fd);
	}
	len = ft_strlen(path);
	if ((ft_strncmp(path + len - 4, ".xpm", 4)) != 0)
		ft_error("Error\nInvalid file!\n");
}
