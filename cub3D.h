#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
    int     fd;
    int     cnt;
    char    **entire_fd;
    char    *trimmed;
    char    *texture[4];
    int     check_floor_color;
	int     check_ceiling_color;
    int     floor_color;
    int     ceiling_color;
    int     cnt_map_lines;
    char    **map;
    char    **map_copy;
}   t_data;

/*_____ERRORS_____*/
void    ft_error(char *str);
void    free_entire_fd(t_data *game);
void    free_error_fd(char *str, t_data *game);
void    free_map(t_data *game);
void    free_error_map(char *str, t_data *game);
void    free_map_copy(t_data *game);
void    free_err_all_maps(char *str, t_data *game);

/*_____INIT_____*/
void    init_struct(t_data *game);

/*_____PARSING_____*/
void    parse(t_data *game, char *file);
int     check_texture(t_data *game, char *line);
void     check_color(t_data *game, char *line);
void    parse_map(t_data *game, int map_start_index);

/*_____MAP_____*/
void    map_is_valid(t_data *game);


#endif