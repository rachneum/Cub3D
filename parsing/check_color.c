#include "../cub3D.h"

static int	parse_color(char *str)
{
	char	**rgb;
	char	*cleaned[3];
	int		i;
	int		j;
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
	i = -1;
	while (++i < 3)
	{
		cleaned[i] = ft_strtrim(rgb[i], " \t");
		if (!cleaned[i] || cleaned[i][0] == '\0')
			ft_error("ERROR: RGB component is empty or invalid!\n");
		j = -1;
		while (cleaned[i][++j])
		{
			if (!ft_isdigit(cleaned[i][j]))
				ft_error("ERROR: RGB components must be numbers!\n");
		}
	}
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("ERROR: RGB values must be between 0 and 255!\n");
	i = 0;
	while (i < 3)
		free(cleaned[i++]);
	return (1);
}

int	check_color(t_data *game, char *line)
{
	char	*value;

	if (ft_strncmp(line, "F", 1) == 0)
	{
		if (game->check_floor_color != 0)
			ft_error("ERROR\nDuplicate floor color!\n");
		value = ft_strtrim(line + 2, " \n");
		if (value[0] == '\0' || !value)
		{
			free(value);
			ft_error("ERROR\nColor value is missing!\n");
		}
		game->check_floor_color = parse_color(value);
		free(value);
		return (1);
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		if (game->check_ceiling_color != 0)
			ft_error("ERROR\nDuplicate ceiling color!\n");
		value = ft_strtrim(line + 2, " \n");
		if (!value || value[0] == '\0')
		{
			free(value);
			ft_error("ERROR\nColor value is missing!\n");
		}
		game->check_ceiling_color = parse_color(value);
		free(value);
		return (1);
	}
	return (0);
}
