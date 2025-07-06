#include "../cub3d.h"

static int 	create_trgb(int t, t_data *game)
{
	return ((t << 24) | (game->r << 16) | (game->g << 8) | game->b);
}

static void	free_str_array(char **arr)
{
    int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int  parse_color(char *str, t_data *game)
{
    int     i;
    char    **rgb;
    char    *cleaned[3];
    int     j;

    i = -1;
	game->comma_cnt = 0;
    while(str[++i])
    {
        if (str[i] == ',')
        {
            game->comma_cnt++;
            if (str[i + 1] == ',' || i == 0 || str[i + 1] == '\0')
                ft_error("Error\nInvalid file!\n");
        }
    }
    if (game->comma_cnt != 2)
        ft_error("Error\nInvalid file!\n");
    rgb = ft_split(str, ',');
    if (!rgb)
        ft_error("Error\nInvalid file!\n");
    i = 0;
    while (rgb[i])
        i++;
    if (i != 3)
    {
        free_str_array(rgb);
        ft_error("Error\nInvalid file!\n");
    }
    i = -1;
    while (++i < 3)
    {
        cleaned[i] = ft_strtrim(rgb[i], " \t");
        if (!cleaned[i] || cleaned[i][0] == '\0')
        {
            j = 0;
            while (j <= i)
            {
                free(cleaned[j]);
                j++;
            }
            free_str_array(rgb);
				ft_error("Error\nInvalid file!\n");
        }
        j = -1;
        while (cleaned[i][++j])
        {
            if (!ft_isdigit(cleaned[i][j]))
            {
                j = 0;
                while (j <= i)
                {
                    free(cleaned[j]);
                    j++;
                }
                free_str_array(rgb);
                ft_error("Error\nInvalid file!\n");
            }
        }
    }
    game->r = ft_atoi(cleaned[0]);
    game->g = ft_atoi(cleaned[1]);
    game->b = ft_atoi(cleaned[2]);
    if (game->r < 0 || game->r > 255 || game->g < 0 || game->g > 255 || game->b < 0 || game->b > 255)
    {
        i = 0;
        while (i < 3)
            free(cleaned[i++]);
        free_str_array(rgb);
        ft_error("Error\nFile invalid!\n");
    }
    i = 0;
	while (i < 3)
		free(cleaned[i++]);
    free_str_array(rgb);
    return (create_trgb(0, game));
}

static void	c_color(t_data *game, char *line)
{
	char	*value;

	if (game->check_ceiling_color != 0)
		ft_error("Error\nInvalid file!\n");
	value = ft_strtrim(line + 2, " \n");
	if (value[0] == '\0' || !value)
	{
		free(value);
		ft_error("Error\nInvalid file!\n");
	}
	game->check_ceiling_color = 1;
	game->ceiling_color = parse_color(value, game);
	printf("%s\n", line);
	free(value);
}

static void	f_color(t_data *game, char *line)
{
	char	*value;

	if (game->check_floor_color != 0)
			ft_error("Error\nInvalid file!\n");
	value = ft_strtrim(line + 2, " \n");
	if (value[0] == '\0' || !value)
	{
		free(value);
		ft_error("Error\nInvalid file!\n");
	}
	game->check_floor_color = 1;
	game->floor_color = parse_color(value, game);
	printf("%s\n", line);
	free(value);
}

void	check_color(t_data *game, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
		f_color(game, line);
	else if (ft_strncmp(line, "C", 1) == 0)
		c_color(game, line);
}
