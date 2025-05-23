#include "../cub3D.h"

int	check_east(t_data *game, char *line)
{
	char	*path;

	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (game->texture[3] != NULL)
			ft_error("ERROR: Duplicate EA texture!\n");
		path = ft_strtrim(line + 3, " \n");
		if (!path || path[0] == '\0')
		{
			free(path);
			ft_error("ERROR: EA texture path is missing!\n");
		}
		if (check_textures_path(path))
	    	ft_error("ERROR: Invalid texture path");
		game->texture[3] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}
	return (0);
}

int check_west(t_data *game, char *line)
{
	char	*path;

	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (game->texture[2] != NULL)
			ft_error("ERROR: Duplicate WE texture!\n");
		path = ft_strtrim(line + 3, " \n");
		if (!path || path[0] == '\0')
		{
			free(path);
			ft_error("ERROR: WE texture path is missing!\n");
		}
		if (check_textures_path(path))
	    	ft_error("ERROR: Invalid texture path");
		game->texture[2] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}
	return (0);
}

int check_south(t_data *game, char *line)
{
	char	*path;

	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (game->texture[1] != NULL)
			ft_error("ERROR: Duplicate SO texture!\n");
		path = ft_strtrim(line + 3, " \n");
		if (!path || path[0] == '\0')
		{
			free(path);
			ft_error("ERROR: SO texture path is missing!\n");
		}
		if (check_textures_path(path))
	    	ft_error("ERROR: Invalid texture path");
		game->texture[1] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}
	return (0);
}

int check_north(t_data *game, char *line)
{
	char	*path;

	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (game->texture[0] != NULL)
			ft_error("ERROR: Duplicate NO texture!\n");
		path = ft_strtrim(line + 3, " \n");//strtrim va supprimer les espaces et \n. line + 3 pour pointer sur le "./...".
		if (!path || path[0] == '\0')
		{
			free(path);
			ft_error("ERROR: NO texture path is missing!\n");
		}
		if (check_textures_path(path))
	    	ft_error("ERROR: Invalid texture path");
		game->texture[0] = ft_strdup(path);
		free(path);
		printf ("%s\n", line);
		return (1);
	}

	return (0);
}
