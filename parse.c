#include "cub3D.h"

static void	parse_map(void)//Parsing map.
{
	printf("SUCCESS\n");
}

//Lire map ligne par ligne et stocker copie de ma map.
//Verifier que toutes les txt y sont
//Verifier si txt et couleurs sont correctes

static int	check_txts_and_clrs(char *line)//Checker textures et couleurs.
{
	//Vérifier qu'il n'y ai pas 2 fois la même info.
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
	{
		printf ("%s\n", line);
		return (0);
	}
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		printf ("%s\n", line);
		return (0);
	}
	return (1);
}

static int	read_file(char *file)//Lire mon fichier .cub ligne par ligne.
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
			if (check_txts_and_clrs(line))
			{
				printf("TEST\n");
				return (1);
			}
		}
		free(line);
	}
	return (0);
}

void    parse(char *file)
{
    if (read_file(file))
		parse_map();
}
