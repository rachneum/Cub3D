#include "../cub3D.h"

int	check_color(t_data *game, char *line)
{
	char	*value;

	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (game->floor_color != -1)
			ft_error("ERROR: Duplicate floor color!\n");
		value = ft_strtrim(line + 2, " \n");
		//game->floor_color = parse_color(value);
		game->floor_color = ft_atoi(value);
		printf("%s\n", line);
		free(value);
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (game->ceiling_color != -1)
			ft_error("ERROR: Duplicate ceiling color!\n");
		value = ft_strtrim(line + 2, " \n");
		//game->ceiling_color = parse_color(value);
		game->ceiling_color = ft_atoi(value);
		printf("%s\n", line);
		free(value);
		return (1);
	}
	return (0);
}
