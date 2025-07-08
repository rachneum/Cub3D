/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:53:02 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/08 13:50:52 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	create_trgb(int t, t_data *game)
{
	return ((t << 24) | (game->r << 16) | (game->g << 8) | game->b);
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
