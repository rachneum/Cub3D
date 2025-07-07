/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:01:39 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/07 18:03:19 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_textures_path(char *path)
{
	int	len;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Error\nInvalid file!\n");
		close (fd);
	}
	len = ft_strlen(path);
	if ((ft_strncmp(path + len - 4, ".xpm", 4)) != 0)
		ft_error("Error\nInvalid file!\n");
}
