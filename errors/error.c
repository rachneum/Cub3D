#include "../cub3d.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	free_entire_fd(t_data *game)
{
	int i;

	i = 0;
	if (!game->entire_fd)
		return ;
	while (game->entire_fd[i])
		free(game->entire_fd[i++]);
	free(game->entire_fd);
	game->entire_fd = NULL;
}

void	free_error_fd(char *str, t_data *game)
{
	free_entire_fd(game);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
