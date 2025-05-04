#include "../cub3D.h"

//Error si texture ou couleur manquante.
//Régler double couleur.
void	parse_map(void)//Parsing map.
{
	printf("SUCCESS\n");
}

/*static int	check_txts_path(char *path)
{

}*/

int	check_color(t_data *game, char *line)
{
	char	*value;

	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (game->floor_color != -1)
			ft_error("ERROR: Duplicate floor color!\n");
		value = ft_strtrim(line + 2, " \n");
		//game->floor_color = parse_color(value); // fonction à écrire
		free(value);
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (game->ceiling_color != -1)
			ft_error("ERROR: Duplicate ceiling color!\n");
		value = ft_strtrim(line + 2, " \n");
		//game->ceiling_color = parse_color(value); // fonction à écrire
		free(value);
		return (1);
	}
	return (0);
}


//Lire map ligne par ligne et stocker copie de ma map.
//Verifier que toutes les txt y sont
//Verifier si txt et couleurs sont correctes

int	check_texture_and_color(t_data *game, char *line)//Checker textures et couleurs.
{
	char	*path;
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		//Vérifier la validité du chemin avec fonction checkpath_txts. check que c'est bien un fichier avec une extension .xpm, vérifier que le fichier est bien lisible.
		if (game->texture[0] != NULL)
			ft_error("ERROR: Duplicate NO texture!\n");
		path = ft_strtrim(line + 3, " \n");//line + 3 donne le chemin et " \n" nettoie les espaces eventuels.
		//if (!check_txts_path(path))//Vérifie que c'est un fichier.xpm accessible.
		//	ft_error("ERROR: Invalid texture path");
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
		//if (!check_txts_path(path))
		//	ft_error("ERROR: Invalid texture path");
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
		//if (!check_txts_path(path))
		//	ft_error("ERROR: Invalid texture path");
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
		//if (!check_txts_path(path))
		//	ft_error("ERROR: Invalid texture path");
		game->texture[3] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
	{
		printf ("%s\n", line);
		return check_color(game, line);
	}
	return (0);
}
