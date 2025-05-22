#include "../cub3D.h"

static int	check_textures_path(char *path)//Vérifie chemin vers la texture et format.
{
    int	len;
	int fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_error("ERROR: Opening texture file failure!\n");
		close (fd);
	}
	//Check si path n'existe pas
	len = ft_strlen(path);
	if ((ft_strncmp(path + len - 4, ".xpm", 4)) != 0)
		ft_error("ERROR: Texture format is invalid!\n");//->Vérifie format fichier texture.
	return (0);
}

int	check_texture(t_data *game, char *line)//Protéger path dans mes conditions au cas où il est vide!
{
	char	*path;

	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (game->texture[0] != NULL)
			ft_error("ERROR: Duplicate NO texture!\n");
		path = ft_strtrim(line + 3, " \n");//strtrim va supprimer les espaces et \n. line + 3 pour pointer sur le "./...".
		if (check_textures_path(path))
	    	ft_error("ERROR: Invalid texture path");
		game->texture[0] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (game->texture[1] != NULL)
			ft_error("ERROR: Duplicate SO texture!\n");
		path = ft_strtrim(line + 3, " \n");
		if (check_textures_path(path))
	    	ft_error("ERROR: Invalid texture path");
		game->texture[1] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (game->texture[2] != NULL)
			ft_error("ERROR: Duplicate WE texture!\n");
		path = ft_strtrim(line + 3, " \n");
		if (check_textures_path(path))
	    	ft_error("ERROR: Invalid texture path");
		game->texture[2] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (game->texture[3] != NULL)
			ft_error("ERROR: Duplicate EA texture!\n");
		path = ft_strtrim(line + 3, " \n");
		if (check_textures_path(path))
	    	ft_error("ERROR: Invalid texture path");
		game->texture[3] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		return (check_color(game, line));
		printf ("%s\n", line);
	}
	return (0);
}
