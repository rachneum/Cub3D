#include "../cub3d.h"

static void	allocation_map(t_data *game)
{
	if (game->cnt_map_lines == 0)
		free_error_fd("Error\nWhere is the map?\n", game);
		game->map = malloc(sizeof(char *) * (game->cnt_map_lines + 1));
	if (!game->map)
		free_error_fd("Error\nMalloc failure!\n", game);
}

static int	map_content(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '0' && line[i] != '1' && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

void	parse_map(t_data *game, int map_start_index)
{
    int		i;
    int		j;

	i = map_start_index - 1;
	while(game->entire_fd[++i])
	{
		if (!map_content(game->entire_fd[i]))
			free_error_fd("Error\nInvalid map!\n", game);
		if (ft_strlen(game->entire_fd[i]) > 0 && game->entire_fd[i][0] != '\n')
			game->cnt_map_lines++;
	}
	allocation_map(game);
	i = map_start_index - 1;
	j = 0;
	while (game->entire_fd[++i])
	{
		if (ft_strlen(game->entire_fd[i]) > 0 && game->entire_fd[i][0] != '\n')
		{
			game->map[j] = ft_strdup(game->entire_fd[i]);
			if (!game->map[j])
				free_error_fd("Error\nFailure map copy!\n", game);
			j++;
		}
	}
	game->map[j] = NULL;
}
