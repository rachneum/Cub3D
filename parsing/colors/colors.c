/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:54:57 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/08 13:52:46 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	extract_rgb_values(t_data *game, char *str, int i)
{
	game->cleaned = malloc(sizeof(char *) * 3);
	if (!game->cleaned)
		ft_error("Error\nMalloc failed!\n");
	game->comma_cnt = 0;
	while (str[++i])
	{
		if (str[i] == ',')
		{
			game->comma_cnt++;
			if (str[i + 1] == ',' || i == 0 || str[i + 1] == '\0')
				free_error_cleaned(game);
		}
	}
	if (game->comma_cnt != 2)
		free_error_cleaned(game);
	game->rgb = ft_split(str, ',');
	if (!game->rgb)
		free_error_cleaned(game);
}

static int	parse_color(char *str, t_data *game, int i, int j)
{
	extract_rgb_values(game, str, -1);
	while (game->rgb[i])
		i++;
	if (i != 3)
		free_str_array_error(game);
	validate_rgb_components(game, -1, j);
	game->r = ft_atoi(game->cleaned[0]);
	game->g = ft_atoi(game->cleaned[1]);
	game->b = ft_atoi(game->cleaned[2]);
	if (game->r < 0 || game->r > 255 || game->g < 0 || game->g > 255
		|| game->b < 0 || game->b > 255)
	{
		i = 0;
		while (i < 3)
			free(game->cleaned[i++]);
		free_str_array_error(game);
	}
	i = 0;
	while (i < 3)
		free(game->cleaned[i++]);
	free(game->cleaned);
	free_str_array(game->rgb);
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
	game->ceiling_color = parse_color(value, game, 0, -1);
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
	game->floor_color = parse_color(value, game, 0, -1);
	free(value);
}

void	check_color(t_data *game, char *line)
{
	if (ft_strncmp(line, "F", 1) == 0)
		f_color(game, line);
	else if (ft_strncmp(line, "C", 1) == 0)
		c_color(game, line);
}
