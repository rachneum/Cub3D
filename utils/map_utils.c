#include "../cub3D.h"

int	count_length(char *file)
{
	int		fd;
	int		leng;
	char	*line;

	leng = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("ERROR: Map file opening has failed!\n");
	while ((line = get_next_line(fd)))
	{
		if (maps_content(file))
		{
			leng = ft_strlen(line);
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

