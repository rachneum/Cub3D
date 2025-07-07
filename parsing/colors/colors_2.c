/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:53:02 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/07 17:53:03 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	create_trgb(int t, t_data *game)
{
	return ((t << 24) | (game->r << 16) | (game->g << 8) | game->b);
}

void	free_str_array(char **arr)
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

void	free_str_array_error(t_data *game)
{
	free_str_array(game->rgb);
	ft_error("Error\nInvalid file!\n");
}

void	validate_rgb_components(t_data *game, int i, int j)
{
	while (++i < 3)
	{
		game->cleaned[i] = ft_strtrim(game->rgb[i], " \t");
		if (!game->cleaned[i] || game->cleaned[i][0] == '\0')
		{
			j = -1;
			while (++j <= i)
				free(game->cleaned[j]);
			free_str_array_error(game);
		}
		j = -1;
		while (game->cleaned[i][++j])
		{
			if (!ft_isdigit(game->cleaned[i][j]))
			{
				j = -1;
				while (++j <= i)
					free(game->cleaned[j]);
				free_str_array_error(game);
			}
		}
	}
}

void	extract_rgb_values(t_data *game, char *str, int i)
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
			{
				free(game->cleaned);
				ft_error("Error\nInvalid file!\n");
			}
		}
	}
	if (game->comma_cnt != 2)
	{
		free(game->cleaned);
		ft_error("Error\nInvalid file!\n");
	}
	game->rgb = ft_split(str, ',');
	if (!game->rgb)
	{
		free(game->cleaned);
		ft_error("Error\nInvalid file!\n");
	}
}
