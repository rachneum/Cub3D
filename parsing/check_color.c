#include "../cub3D.h"

static int	parse_color(char *str)//Check RGB.
{
	char	**rgb;
	int		i;
	int		r, g, b;

	rgb = ft_split(str, ',');
	if (!rgb)
		ft_error("ERROR: Failed to split color string!\n");
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		ft_error("ERROR: Invalid RGB format. Must be R,G,B!\n");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("ERROR: RGB values must be between 0 and 255!\n");
	return (1);
}

int	check_color(t_data *game, char *line)
{
	char	*value;

	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (game->check_floor_color != 0)
			ft_error("ERROR: Duplicate floor color!\n");
		value = ft_strtrim(line + 2, " \n");
		game->check_floor_color = parse_color(value);
		printf("%s\n", line);
		free(value);
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (game->check_ceiling_color != 0)
			ft_error("ERROR: Duplicate ceiling color!\n");
		value = ft_strtrim(line + 2, " \n");
		game->check_ceiling_color = parse_color(value);
		printf("%s\n", line);
		free(value);
		return (1);
	}
	return (0);
}
