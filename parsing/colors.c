#include "../cub3d.h"

static int  create_trgb(int t, int r, int g, int b)
{
    return ((t << 24) | (r << 16) | (g << 8) | b);
}

static void free_str_array(char **arr)
{
    int i;

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

static int  parse_color(char *str)
{
    int     i;
    int     comma_cnt;
    char    **rgb;
    char    *cleaned[3];
    int     j;
    int     r;
    int     g;
    int     b;

    i = -1;
    comma_cnt = 0;
    while(str[++i])
    {
        if (str[i] == ',')
        {
            comma_cnt++;
            if (str[i + 1] == ',' || i == 0 || str[i + 1] == '\0')
                ft_error("Error\nInvalid file!\n");
        }
    }
    if (comma_cnt != 2)
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
    r = ft_atoi(cleaned[0]);
    g = ft_atoi(cleaned[1]);
    b = ft_atoi(cleaned[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
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
    return (create_trgb(0, r, g, b));
}

void check_color(t_data *game, char *line)
{
    char    *value;

    if (ft_strncmp(line, "F", 1) == 0)
    {
        if (game->check_floor_color != 0)
            ft_error("Error\nInvalid file!\n");
        value = ft_strtrim(line + 2, " \n");
        if (value[0] == '\0' || !value)
		{
			free(value);
			ft_error("Error\nInvalid file!\n");
		}
        game->check_floor_color = 1;
        game->floor_color = parse_color(value);
        printf("%s\n", line);
        free(value);
    }
    else if (ft_strncmp(line, "C", 1) == 0)
    {
        if (game->check_ceiling_color != 0)
            ft_error("Error\nInvalid file!\n");
        value = ft_strtrim(line + 2, " \n");
        if (value[0] == '\0' || !value)
		{
			free(value);
			ft_error("Error\nInvalid file!\n");
		}
        game->check_ceiling_color = 1;
        game->ceiling_color = parse_color(value);
        printf("%s\n", line);
        free(value);
    }
}
