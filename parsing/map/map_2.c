/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:56:34 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/07 17:56:35 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static char	**copy_map(char **src_map)
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
	int	i;

	i = 0;
	if (!start_pos(game))
		free_error_map("Error\nInvalid map\n", game);
	map_is_closed(game);
	printf("MAP COPY:\n");
	while (game->map_copy[i])
		printf("%s\n", game->map_copy[i++]);
	map_borders(game);
	check_invalid_zero(game);
}
