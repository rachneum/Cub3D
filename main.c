#include "cub3d.h"

int main(int argc, char **argv)
{
	int		len;
	t_data	*game;

	if (argc != 2)
		ft_error("Error\nNot the right amount of arguments!\n");
	len = ft_strlen(argv[1]);
	if ((ft_strncmp(argv[1] + len - 4, ".cub", 4)) != 0)
		ft_error("Error\nInvalid map format!\n");
	game = malloc(sizeof(t_data));
	if (!game)
		ft_error("Error\nFailed allocation memory structure!\n");
	init_struct(game);
	parse(game, argv[1]);
	map_is_valid(game);
	free_map(game);
	free_map_copy(game);
	free(game);
	return (0);
}
