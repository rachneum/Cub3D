#include "cub3D.h"

int	main(int argc, char **argv)
{
	int		len;
	t_data	game;

	if (argc != 2)
		ft_error("ERROR: Not the right amount of arguments!\n");
	len = ft_strlen(argv[1]);
	if ((ft_strncmp(argv[1] + len - 4, ".cub", 4)) != 0)
		ft_error("ERROR: Map format is invalid!\n");//Vérifie format map.
	init_game_struct(&game, argv[1]);//Initialise tous les éléments de ma structure principale.
	parse(&game, argv[1]);//Parsing du fichier .cub.
	map_is_valid(&game);//Validité de ma map.
	
	return (0);
}
