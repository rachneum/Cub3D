#include "../cub3D.h"

static char **read_lines(const char *file)
{
	char	**lines;
	char	*line;
	int		count;
	int		i;
	int		fd;

	count = 0;
	i = 0;
	fd = open(file, O_RDONLY);//Ouvrir une première fois pour compter les lignes.
	if (fd == -1)
		ft_error("ERROR: File opening failure!\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	fd = open(file, O_RDONLY);//Ouvir une 2eme fois afin de stocker.
	if (fd == -1)
		ft_error("ERROR: Failure reopening file\n");
	lines = malloc(sizeof(char *) * (count + 1));
	if (!lines)
		ft_error("ERROR: Malloc failed\n");
	while ((line = get_next_line(fd)) != NULL)
		lines[i++] = line;
	lines[i] = NULL;
	close(fd);
	return (lines);
}

void	parse(t_data *game, char *file)
{
	char	**lines;
	char	*trimmed;
	int		i;

	i = 0;
	lines = read_lines(file);
	while (lines[i])
	{
		trimmed = ft_strtrim(lines[i], " ");
		if (ft_strlen(trimmed) > 0)
		{
			if (!check_texture(game, trimmed))
			{
				free(trimmed);
				break;
			}
		}
		free(trimmed);
		i++;
	}
	if (!parse_map(game, &lines[i]))
		ft_error("ERROR: Map parsing has failed!\n");
	i = 0;
	while (game->map[i])
		printf("%s\n", game->map[i++]);
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}
