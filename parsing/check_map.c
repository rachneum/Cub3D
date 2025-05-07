#include "../cub3D.h"

static int	maps_content(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	parse_map(t_data *game, char **lines)
{
	int		i;
	int		j;
	int		map_lines;
	char	*trimmed;

	i = 0;
	map_lines = 0;
	while (lines[map_lines])
	{
		char *trimmed = ft_strtrim(lines[map_lines], " \n");
		if (ft_strlen(trimmed) > 0 && maps_content(trimmed))
			map_lines++;
		else if (ft_strlen(trimmed) > 0)
		{
			free(trimmed);
			return (0);
		}
		free(trimmed);
	}
	game->map = malloc(sizeof(char *) * (map_lines + 1));
	if (!game->map)
		ft_error("Malloc failed\n");
	i = 0;
	j = 0;
	while (j < map_lines)
	{
		trimmed = ft_strtrim(lines[i], " \n");
		if (ft_strlen(trimmed) > 0 && maps_content(trimmed))
			game->map[j++] = ft_strdup(trimmed);
		free(trimmed);
		i++;
	}
	game->map[j] = NULL;
	return (1);
}
