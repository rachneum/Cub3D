#include "../cub3D.h"
	
static int	read_file(t_data *game, char *file)//Lire mon fichier .cub ligne par ligne.
{
	//Gnl map.cub voir si couleurs ou textures existent suivit du bon chemin. (map tjs en dernier).
	//Une fois fait, compter lignes map.
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("ERROR: Opening file failure!\n");
	while ((line = get_next_line(fd))!= NULL)
	{
		if (ft_strlen(line) > 0)
		{
			line = ft_strtrim(line, " ");
			if (!check_texture_and_color(game, line))
			{
				printf("TEST\n");
				return (1);
			}
		}
		free(line);
	}
	return (0);
}

void    parse(t_data *game, char *file)
{
    if (read_file(game, file))
		parse_map();
}
