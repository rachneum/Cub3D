#include "../cub3D.h"

int	check_texture_file(char *file)
{
    int	fd;

	fd = open(file, 0_RDONLY);
	if (fd == -1)
		ft_error("ERROR: File opening failure!\n");
	if (!fd)
		return ();
	return ();
}