/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:56:34 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/08 13:42:48 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	map_is_closed(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	game->map_copy = copy_map(game->map);
	if (!game->map_copy)
		ft_error("Error\nInvalid map!\n");
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				if (flood_fill(game, y, x))
					free_err_all_maps("Error\nInvalid map!\n", game);
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	is_line_truly_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	check_map_empty_lines(t_data *game)
{
	int	i;
	int	in_map;
	int	empty_found;

	i = 0;
	in_map = 0;
	empty_found = 0;
	while (game->map[i])
	{
		if (is_line_truly_empty(game->map[i]))
		{
			if (in_map)
				empty_found = 1;
		}
		else
		{
			if (empty_found)
				free_error_map("Error\nInvalid map\n", game);
			in_map = 1;
		}
		i++;
	}
}

static int	start_pos(t_data *game)
{
	int	y;
	int	count;
	int	x;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	else if (!count)
		return (0);
	return (1);
}

void	map_is_valid(t_data *game)
{
	if (!start_pos(game))
		free_error_map("Error\nInvalid map\n", game);
	check_map_empty_lines(game);
	map_is_closed(game);
	map_borders(game);
	check_invalid_zero(game);
}
