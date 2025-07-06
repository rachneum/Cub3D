#include "../cub3d.h"

static int  is_valid_element(char *line, t_data *game)
{
    if (!line)
        return (0);
    if (ft_strlen(line) == 0)
        return (1);
        if (ft_strncmp(line, "NO", 2) == 0)
        {
            game->cnt += 1;
            return (1);
        }
        if (ft_strncmp(line, "SO", 2) == 0)
        {
            game->cnt += 2;
            return (1);
        }
        if (ft_strncmp(line, "WE", 2) == 0)
        {
            game->cnt += 3;
            return (1);
        }
        if (ft_strncmp(line, "EA", 2) == 0)
        {
            game->cnt += 4;
            return (1);
        }
        if (ft_strncmp(line, "F", 1) == 0)
        {
            game->cnt += 5;
            return (1);
        }
        if (ft_strncmp(line, "C", 1) == 0)
        {
            game->cnt += 6;
            return (1);
        }
    return (0);
}

static void open_file(t_data *game, char *file)
{
    game->fd = open(file, O_RDONLY);
    if (game->fd == -1)
        ft_error("Error\nFile opening failure!\n");
}

static char **read_lines(t_data *game, char *file)
{
    char    *line;
    int     count;
    char    **entire_fd;
    int     i;

    count = 0;
    open_file(game, file);
    while ((line = get_next_line(game->fd)) != NULL)
    {
        count++;
        free(line);
    }
    close(game->fd);
    if (count == 0)
        ft_error("Error\nFile must contain something!\n");
    open_file(game, file);
    entire_fd = malloc(sizeof(char *) * (count + 1));
    if (!entire_fd)
        ft_error("Error\nMalloc failed\n");
    i = 0;
    while ((line = get_next_line(game->fd)) != NULL)
        entire_fd[i++] = line;
    entire_fd[i] = NULL;//Permet de la marquer la fin pour savoir où s'arrête mon tableau (comme un \0).
    close(game->fd);
    return (entire_fd);
}

void    parse(t_data *game, char *file)
{
    int     i;
    int     j;
    int     map_start_index;

    game->entire_fd = read_lines(game, file);
    i = -1;
    map_start_index = -1;
    while (game->entire_fd[++i])
    {
        if (game->cnt == 21)
            break ;
        game->trimmed = ft_strtrim(game->entire_fd[i], " \t");
        if (!game->trimmed)
            free_error_fd("Error\nTrim failure!\n", game);
        if (!is_valid_element(game->trimmed, game))
        {
            free(game->trimmed);
            free_error_fd("Error\nInvalid file!\n", game);
        }
        if (game->trimmed)
            free(game->trimmed);
    }
    map_start_index = i;
    j = -1;
    while (game->entire_fd[++j])
    {
        game->trimmed = ft_strtrim(game->entire_fd[j], " \t");
        if (!game->trimmed)
            free_error_fd("Error\nTrim failure!\n", game);
        if (ft_strlen(game->trimmed) > 0)
        {
            if (!check_texture(game, game->trimmed))
			{
				free(game->trimmed);
				break;
			}
        }
        if (game->trimmed)
			free(game->trimmed);
    }
    parse_map(game, map_start_index);
    i = 0;
    free_entire_fd(game);
}
