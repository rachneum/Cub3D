#include "../cub3D.h"

int	count_length(char *file)
{
	int		fd;
	int		leng;
	char	*line;
	char	*trimmed;

	leng = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("ERROR: Map file opening has failed!\n");
	while ((line = get_next_line(fd)))
	{
		trimmed = ft_strtrim(line, " \n");
		free(line);
		if (ft_strlen(trimmed) > 0 && maps_content(trimmed))
		{
			leng = ft_strlen(trimmed);
			free(trimmed);
			break;
		}
		free(trimmed);
	}
	close(fd);
	return (leng);
}
