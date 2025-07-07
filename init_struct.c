/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:08:27 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/07 18:08:43 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_data *game)
{
	if (!game)
		return ;
	game->fd = -1;
	game->cnt = 0;
	game->entire_fd = NULL;
	game->trimmed = NULL;
	game->texture[0] = NULL;
	game->texture[1] = NULL;
	game->texture[2] = NULL;
	game->texture[3] = NULL;
	game->check_floor_color = 0;
	game->check_ceiling_color = 0;
	game->r = 0;
	game->g = 0;
	game->b = 0;
	game->cleaned = NULL;
	game->cnt_map_lines = 0;
	game->map = NULL;
	game->map_copy = NULL;
}
