#include "../cub3D.h"

int	maps_content(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int parse_map(t_data *game, char **lines)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	game->nb_map_lines = 0;
	while (lines[i])
	{
		if (!maps_content(lines[i]))
			ft_free_error("ERROR: Wrong element in map!\n", game);
		trimmed = ft_strtrim(lines[i], "\n");
		if (!trimmed)
			ft_error("ERROR: Trim has failed!\n");
		if (ft_strlen(trimmed) > 0)
			game->nb_map_lines++;
		free(trimmed);
		i++;
	}
	if (!game->nb_map_lines)
		ft_error("ERROR: Where is the map?\n");
	game->map = malloc(sizeof(char *) * (game->nb_map_lines + 1));
	if (!game->map)
		ft_error("ERROR: Malloc has failed!\n");
	i = 0;
	j = 0;
	while (lines[i])
	{
		trimmed = ft_strtrim(lines[i], "\n");
		if (!trimmed)
			ft_error("ERROR: Trim has failed!\n");

		if (ft_strlen(trimmed) > 0)
		{
			game->map[j] = ft_strdup(trimmed);
			if (!game->map[j])
				ft_error("ERROR: Strdup has failed!\n");
			j++;
		}
		free(trimmed);
		i++;
	}
	game->map[j] = NULL;
	return (1);
}
