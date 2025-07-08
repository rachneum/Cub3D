/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:03:39 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/08 13:35:22 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_east(t_data *game, char *line)
{
	char	*path;

	if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (game->texture[3] != NULL)
			ft_error("Error\nInvalid file!\n");
		path = ft_strtrim(line + 3, " \n");
		if (!path || path[0] == '\0')
		{
			free(path);
			ft_error("Error\nInvalid file!\n");
		}
		check_textures_path(path);
		game->texture[3] = ft_strdup(path);
		if (!game->texture[3])
		{
			free(path);
			free_txt(game);
			ft_error("Error\nInvalid file!\n");
		}
		free(path);
		free_txt(game);
		return (1);
	}
	return (0);
}

static int	check_west(t_data *game, char *line)
{
	char	*path;

	if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (game->texture[2] != NULL)
			ft_error("Error\nInvalid file!\n");
		path = ft_strtrim(line + 3, " \n");
		if (!path || path[0] == '\0')
		{
			free(path);
			ft_error("Error\nInvalid file!\n");
		}
		check_textures_path(path);
		game->texture[2] = ft_strdup(path);
		if (!game->texture[2])
		{
			free(path);
			free_txt(game);
			ft_error("Error\nInvalid file!\n");
		}
		free(path);
		free_txt(game);
		return (1);
	}
	return (0);
}

static int	check_south(t_data *game, char *line)
{
	char	*path;

	if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (game->texture[1] != NULL)
			ft_error("Error\nInvalid file!\n");
		path = ft_strtrim(line + 3, " \n");
		if (!path || path[0] == '\0')
		{
			free(path);
			ft_error("Error\nInvalid file!\n");
		}
		check_textures_path(path);
		game->texture[1] = ft_strdup(path);
		if (!game->texture[1])
		{
			free(path);
			free_txt(game);
			ft_error("Error\nInvalid file!\n");
		}
		free(path);
		free_txt(game);
		return (1);
	}
	return (0);
}

static int	check_north(t_data *game, char *line)
{
	char	*path;

	if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (game->texture[0] != NULL)
			ft_error("Error\nInvalid file!\n");
		path = ft_strtrim(line + 3, " \n");
		if (!path || path[0] == '\0')
		{
			free(path);
			ft_error("Error\nInvalid file!\n");
		}
		check_textures_path(path);
		game->texture[0] = ft_strdup(path);
		if (!game->texture[0])
		{
			free(path);
			free_txt(game);
			ft_error("Error\nInvalid file!\n");
		}
		free(path);
		free_txt(game);
		return (1);
	}
	return (0);
}

int	check_texture(t_data *game, char *line)
{
	if (check_north(game, line))
		return (1);
	if (check_south(game, line))
		return (1);
	if (check_west(game, line))
		return (1);
	if (check_east(game, line))
		return (1);
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		check_color(game, line);
		return (1);
	}
	return (0);
}
