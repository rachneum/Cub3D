/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:49:58 by raneuman          #+#    #+#             */
/*   Updated: 2025/07/08 13:54:04 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

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

void	free_error_cleaned(t_data *game)
{
	free(game->cleaned);
	ft_error("Error\nInvalid file!\n");
}
