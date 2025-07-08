/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:48:58 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/08 13:45:55 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(t_data *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
}

void	free_txt(t_data *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture[i])
		{
			free(game->texture[i]);
			game->texture[i] = NULL;
		}
		i++;
	}
}

void	free_error_map(char *str, t_data *game)
{
	free_map(game);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_map_copy(t_data *game)
{
	int	i;

	i = 0;
	if (!game->map_copy)
		return ;
	while (game->map_copy[i])
		free(game->map_copy[i++]);
	free(game->map_copy);
	game->map_copy = NULL;
}

void	free_err_all_maps(char *str, t_data *game)
{
	free_map(game);
	free_map_copy(game);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
