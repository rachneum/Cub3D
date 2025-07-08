/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:57:20 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/08 13:41:14 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_surroundings(t_data *game, int y, int x)
{
	if (y > 0 && x < (int)ft_strlen(game->map_copy[y - 1])
		&& (game->map_copy[y - 1][x] == ' '
		|| game->map_copy[y - 1][x] == '\t'))
		free_err_all_maps("Error\nInvalid map!\n", game);
	if (game->map_copy[y + 1] && x < (int)ft_strlen(game->map_copy[y + 1])
		&& (game->map_copy[y + 1][x] == ' '
		|| game->map_copy[y + 1][x] == '\t'))
		free_err_all_maps("Error\nInvalid map!\n", game);
	if (x > 0 && (game->map_copy[y][x - 1] == ' '
		|| game->map_copy[y][x - 1] == '\t'))
		free_err_all_maps("Error\nInvalid map!\n", game);
	if (x + 1 < (int)ft_strlen(game->map_copy[y])
		&& (game->map_copy[y][x + 1] == ' '
		|| game->map_copy[y][x + 1] == '\t'))
		free_err_all_maps("Error\nInvalid map!\n", game);
}

void	check_invalid_zero(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			if (game->map_copy[y][x] == '0')
				check_surroundings(game, y, x);
			x++;
		}
		y++;
	}
}

void	map_borders(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x])
		{
			if (y == 0 || game->map_copy[y + 1] == NULL)
			{
				if (game->map_copy[y][x] == '0')
					free_err_all_maps("Error\nInvalid map!\n", game);
			}
			if (x == 0 || x == (int)(ft_strlen(game->map_copy[y]) - 1))
			{
				if (game->map_copy[y][x] == '0')
					free_err_all_maps("Error\nInvalid map!\n", game);
			}
			x++;
		}
		y++;
	}
}

int	flood_fill(t_data *game, int y, int x)
{
	if (y < 0 || x < 0 || !game->map_copy[y]
		|| x >= (int)ft_strlen(game->map_copy[y]))
		return (1);
	if (game->map_copy[y][x] == ' ' || game->map_copy[y][x] == '\t')
		return (1);
	if (game->map_copy[y][x] == '1' || game->map_copy[y][x] == 'X')
		return (0);
	game->map_copy[y][x] = 'X';
	if (flood_fill(game, y - 1, x))
		return (1);
	if (flood_fill(game, y + 1, x))
		return (1);
	if (flood_fill(game, y, x - 1))
		return (1);
	if (flood_fill(game, y, x + 1))
		return (1);
	return (0);
}

char	**copy_map(char **src_map)
{
	int		i;
	char	**copy;
	int		j;

	i = 0;
	while (src_map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (src_map[++i])
	{
		copy[i] = ft_strdup(src_map[i]);
		if (!copy[i])
		{
			j = -1;
			while (++j < i)
				free(copy[j]);
			free(copy);
			return (NULL);
		}
	}
	copy[i] = NULL;
	return (copy);
}
