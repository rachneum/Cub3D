#include "../cub3D.h"

/*int	count_length(char *file)
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
}*/

char	**copy_map(char **src_map)
{
	int		i;
	char	**copy;

	i = 0;
	while (src_map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src_map[i])
	{
		copy[i] = ft_strdup(src_map[i]);
		if (!copy[i])
		{
			int j = 0;
			while (j < i)
			{
				free(copy[j]);
				j++;
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
