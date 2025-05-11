#include "../cub3D.h"

int	count_length(char *file)
{
	int		fd;
	int		leng = 0;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("ERROR: Map file opening has failed!\n");

	while ((line = get_next_line(fd)))
	{
		if (maps_content(line)) // ← vérifie si c'est une ligne de la map
		{
			leng = ft_strlen(line);
			// Enlève le \n s’il est présent
			if (leng > 0 && line[leng - 1] == '\n')
				leng--;
			free(line);
			break;
		}
		free(line);
	}
	close(fd);
	return (leng);
}

